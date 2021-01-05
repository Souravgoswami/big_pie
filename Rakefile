# frozen_string_literal: true
require "bundler/gem_tasks"

task :default do
	puts "\e[38;2;255;255;0m\u2B22 BigPie #{BigPie::VERSION}\e[0m"
end

task :test do
	require_relative File.join(__dir__, %w(tests simple_test))
	puts "\e[38;2;255;255;0m\u2B22 BigPie #{BigPie::VERSION}\e[0m"
	test(27000)
end
