# frozen_string_literal: true
require_relative "lib/big_pie/version"

Gem::Specification.new do |s|
	s.name = "big_pie"
	s.version = BigPie::VERSION
	s.authors = ["Sourav Goswami"]
	s.email = ["souravgoswami@protonmail.com"]
	s.summary = "Calculate N Digits of Pi, argument upto unsigned long long (generally 2 ** 64 - 1)"
	s.description = "Calculate N Digits of Pi, argument upto unsigned long long (generally 2 ** 64 - 1)"
	s.homepage = "https://www.github.com/Souravgoswami/big_pie"
	s.license = "MIT"
	s.required_ruby_version = Gem::Requirement.new(">= 2.1.0")
	s.files = Dir.glob(%w(ext/**/*.{c,rb} lib/**/*.rb LICENCE))
	s.extensions = Dir.glob("ext/**/extconf.rb")
	s.require_paths = %w(lib)
end
