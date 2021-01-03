#include <gmp.h>
#include <inttypes.h>
#include "ruby.h"

#if defined(__GNUC__) && !defined(__clang__) && !defined(__INTEL_COMPILER)
	#pragma GCC optimize ("Ofast")
	#pragma GCC diagnostic warning "-Wall"
#elif defined(__clang__)
	#pragma clang optimize on
	#pragma clang diagnostic warning "-Wall"
#elif defined(__INTEL_COMPILER)
	#pragma intel optimization_level 3
#endif

VALUE calculatePi(volatile VALUE obj, volatile VALUE number) {
	VALUE ary = rb_ary_new() ;
	VALUE shove = rb_intern("<<") ;

	VALUE _rb_one = INT2FIX(0) ;
	if (rb_funcallv_public(number, rb_intern("<"), 1, &_rb_one)) return ary ;

	register uint64_t num = NUM2ULL(number) ;
	register uint64_t index = 0 ;
	register int8_t comp ;

	mpz_t q, t, k, m, x, r ;
	mpz_t temp1 ;

	mpz_init(q) ;
	mpz_init(t) ;
	mpz_init(k) ;
	mpz_init(m) ;
	mpz_init(x) ;
	mpz_init(r) ;
	mpz_init(temp1) ;

	mpz_set_ui(q, 1) ;
	mpz_set_ui(t, 1) ;
	mpz_set_ui(k, 1) ;
	mpz_set_ui(m, 3) ;
	mpz_set_ui(x, 3) ;
	mpz_set_ui(r, 0) ;

	while(index < num) {
		mpz_sub(temp1, r, t) ;
		mpz_addmul_ui(temp1, q, 4) ;
		mpz_submul(temp1, m, t) ;

		comp = mpz_cmp_ui(temp1, 0) ;

		if(comp < 0) {
			++index ;
			VALUE m_to_ui = INT2FIX(mpz_get_ui(m)) ;
			rb_funcallv_public(ary, shove, 1, &m_to_ui) ;

			// r
			mpz_submul(r, m, t) ;
			mpz_mul_ui(r, r, 10) ;

			mpz_submul_ui(m, m, 10) ;
			mpz_mul_ui(q, q, 10) ;
		} else {
			mpz_mul(t, t, x) ;

			// r
			mpz_addmul_ui(r, q, 2) ;
			mpz_mul(r, r, x) ;

			mpz_tdiv_q(m, r, t) ;
			mpz_mul(q, q, k) ;
			mpz_add_ui(k, k, 1) ;
			mpz_add_ui(x, x, 2) ;
		}
	}

	mpz_clear(q) ;
	mpz_clear(t) ;
	mpz_clear(k) ;
	mpz_clear(m) ;
	mpz_clear(x) ;
	mpz_clear(r) ;
	mpz_clear(temp1) ;

	return ary ;
}

void Init_bigpie() {
	VALUE _pi = rb_define_module("BigPie") ;
	rb_define_module_function(_pi, "calculate", calculatePi, 1) ;
}
