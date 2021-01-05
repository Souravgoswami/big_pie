begin
	require 'big_pie'
rescue LoadError
	abort "\e[1;31mbig_pie isn't installed! Please install big_pie before running the tests!\e[0m"
end

require 'bigdecimal/math'

def test(n)
	puts "\e[38;2;255;255;0m\u2B22 Testing #{n} digits of Pi...\e[0m"

	big_math_pi = BigMath.PI(n).to_s[0..n]
	big_pie_pi = BigPie.calculate(n).join.tap { |x| x[1, 0] = ?. }
	big_pie_pi_decimal = BigDecimal(big_pie_pi).to_s[0..n]

	unless big_math_pi == big_pie_pi_decimal
		puts "\e[38;2;255;80;80m\u274c Test Failed!\e[0m"
		exit 1
	else
		puts "\e[38;2;0;200;0m\u2713 Test Ok!\e[0m"
	end
end
