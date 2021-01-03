# BigPie

Welcome to your new gem! In this directory, you'll find the files you need to be able to package up your Ruby library into a gem. Put your Ruby code in the file `lib/big_pie`. To experiment with that code, run `bin/console` for an interactive prompt.

TODO: Delete this and the text above, and describe your gem

## Dependency
This library depends on GMP.

+ Install GMP on Arch Linux:

```
# pacman -S gmp
```

+ On Debian / Ubuntu / LinuxMint:

```
# apt install libgmp-dev
```

Once done, you can follow the installation steps.

## Installation

Add this line to your application's Gemfile:

```ruby
gem 'big_pie'
```

And then execute:

    $ bundle install

Or install it yourself as:

    $ gem install big_pie

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

## Time
The time it takes to calculate a Pi depends on the system.
But you can predict the time for a big number.

It takes to calculate 3*n the size of it will take 10x the time it takes to calculate n.

For example [under no CPU load], if 1000 digits takes 0.005 seconds, to calculate 1000 digits,
it will take 10 * 0.005 = 0.05 seconds to calculate 3000 digits;
and 0.5 seconds to calculate 9000 digits.

## Development
After checking out the repo, run `bin/setup` to install dependencies.
You can also run `bin/console` for an interactive prompt that will allow you to experiment.

To install this gem onto your local machine, run `rake install`.

## Contributing
Bug reports and pull requests are welcome on GitHub at https://github.com/Souravgoswami/big_pie. This project is intended to be a safe, welcoming space for collaboration, and contributors are expected to adhere to the [code of conduct](https://github.com/[USERNAME]/big_pie/blob/master/CODE_OF_CONDUCT.md).

## License

The gem is available as open-source under the terms of the [MIT License](https://opensource.org/licenses/MIT).
