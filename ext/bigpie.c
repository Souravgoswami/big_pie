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

VALUE calculatePi(volatile VALUE obj, VALUE number) {
	VALUE ary = rb_ary_new() ;
	VALUE shove = rb_intern("<<") ;

	uint64_t num = NUM2ULL(number) ;
	uint64_t index = 0 ;
	uint8_t comp ;

	mpz_t q, t, k, m, x, r ;
	mpz_t m_t ;
	mpz_t temp1, temp2 ;

	mpz_init(q) ;
	mpz_init(t) ;
	mpz_init(k) ;
	mpz_init(m) ;
	mpz_init(x) ;
	mpz_init(r) ;
	mpz_init(m_t) ;
	mpz_init(temp1) ;
	mpz_init(temp2) ;

	mpz_set_ui(q, 1) ;
	mpz_set_ui(t, 1) ;
	mpz_set_ui(k, 1) ;
	mpz_set_ui(m, 3) ;
	mpz_set_ui(x, 3) ;
	mpz_set_ui(r, 0) ;

	while(index < num) {
		mpz_mul_ui(temp1, q, 4) ;
		mpz_add(temp1, temp1, r) ;
		mpz_sub(temp1, temp1, t) ;
		mpz_mul(m_t, m, t) ;

		comp = mpz_cmp(m_t, temp1) ;
		if(comp == 1) {
			++index ;
			VALUE m_to_ui = INT2FIX(mpz_get_ui(m)) ;
			rb_funcallv_public(ary, shove, 1, &m_to_ui) ;

			//m
			mpz_mul_ui(temp1, q, 3) ;
			mpz_add(temp1, temp1, r) ;
			mpz_mul_ui(temp1, temp1, 10) ;
			mpz_tdiv_q(temp1, temp1, t) ;
			mpz_mul_ui(temp2, m, 10) ;
			mpz_sub(m, temp1, temp2) ;

			// r
			mpz_set(temp1, m_t) ;
			mpz_sub(temp1, r, temp1) ;
			mpz_mul_ui(r, temp1, 10) ;

			//q
			mpz_mul_ui(q, q, 10) ;
		} else {
			// t
			mpz_mul(t, t, x) ;

			// m
			mpz_mul_ui(temp1, k, 7) ;
			mpz_add_ui(temp1, temp1, 2) ;
			mpz_mul(temp1, temp1, q) ;
			mpz_mul(temp2, r, x) ;
			mpz_add(temp1, temp1, temp2) ;
			mpz_tdiv_q(m, temp1, t) ;

			// r
			mpz_mul_ui(temp1, q, 2) ;
			mpz_add(temp1, temp1, r) ;
			mpz_mul(r, temp1, x) ;

			// q
			mpz_mul(q, q, k) ;

			// k
			mpz_add_ui(k, k, 1) ;

			// x
			mpz_add_ui(x, x, 2) ;
		}
	}

	mpz_clear(q) ;
	mpz_clear(t) ;
	mpz_clear(k) ;
	mpz_clear(m) ;
	mpz_clear(x) ;
	mpz_clear(r) ;
	mpz_clear(m_t) ;
	mpz_clear(temp1) ;
	mpz_clear(temp2) ;

	return ary ;
}

void Init_bigpie() {
	VALUE _pi = rb_define_module("BigPie") ;
	rb_define_module_function(_pi, "calculate", calculatePi, 1) ;
}
