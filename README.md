# BigPie
BigPie is a Rubygem that uses GMP library to calculate Pi up to n digits.

The maximum argument it can accept is a long long unsigned int.

## Dependency
This library depends on GMP, and ruby development library.

+ Install GMP on Arch Linux:

Ruby on Arch Linux provides ruby.h header file, so all you need is the GMP library, make, and GCC:
```
# pacman -S gmp make gcc
```

+ On Debian / Ubuntu / LinuxMint:

```
# apt install libgmp-dev ruby-dev make gcc
```

Once done, you can follow the installation steps.

## Installation

Add this line to your application's Gemfile:

```ruby
gem 'big_pie'
```

And then execute:
```
$ bundle install
```

Or install it yourself as:
```
$ gem install big_pie
```

## Usage

```
irb(main):001:0> require 'big_pie'
=> true

irb(main):002:0> BigPie.calculate(50)
=> [3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5, 8, 9, 7, 9, 3, 2, 3, 8, 4, 6, 2, 6, 4, 3, 3, 8, 3, 2, 7, 9, 5, 0, 2, 8, 8, 4, 1, 9, 7, 1, 6, 9, 3, 9, 9, 3, 7, 5, 1]
```

The calculate(n) is the digit including the mantissa. As you can see, the first 3 is always returned as the 0th element of the array.

Passing 50 will calculate 49 digits after the fraction.

An array is returned because the push operation is faster on Arrays than Strings.
To convert the array to Pi:

```
> BigPie.calculate(100).join.tap { |x| x.insert(1, ?..freeze) }
=> "3.141592653589793238462643383279502884197169399375105820974944592307816406286208998628034825342117067"
```

You can also pass blocks:

```
irb(main):001:0> require 'big_pie'
=> true
irb(main):002:0* ind = 0
=> 0
irb(main):003:0> BigPie.calculate(5) { |x| p [x, ind += 1] }
[3, 1]
[1, 2]
[4, 3]
[1, 4]
[5, 5]
=> nil
```

As you can see, passing blocks won't return an Array because the values are passed to the
block variables instead.

## Time
The time it takes to calculate a Pi depends on the system.
But you can predict the time for a big number.

To calculate 3 * n, it will take 10x the time it takes to calculate n.

For example [under no CPU load], if calculating 1000 digits takes 0.005 seconds,
it will take 10 * 0.005 = 0.05 seconds to calculate 3000 digits;
and 0.5 seconds to calculate 9000 digits.

## Development
After checking out the repo, run `bin/setup` to install dependencies.
You can also run `bin/console` for an interactive prompt that will allow you to experiment.

To install this gem onto your local machine, run `rake install`.

## Contributing
Bug reports and pull requests are welcome on GitHub at https://github.com/Souravgoswami/big_pie.

## Licence

The gem is available as open-source under the terms of the [MIT License](https://opensource.org/licenses/MIT).
