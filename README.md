rndpass
=======

A random password generator for GNU/Linux in C.

Todo
====

- getrandom() syscall will not guarantee to read read more than 256 bytes, this
is not accounted in the randstr() code, although it is unlikely that one would
want to generate a password that long.

Performance
===========

I have written a script that does the same using python, which is in my bin
repository. Using `pv` I benchmarked the performance of rndpass and the bash
equivalent.

I used the following command:

```
while true; do $generator; done | pv -t -b -r > test.txt
```

| program           | measured output |
|-------------------|-----------------|
| rndpass           | ~22KiB/s        |
| python equivalent | ~590B/s         |

(Benchmarks ran on a ThinkPad X200 with an Intel Core2Duo P8600 CPU)

License
=======

rndpass is licensed under the [GNU General Public License 3](https://www.gnu.org/licenses/gpl-3.0.html), or (at your option),
any later version.
