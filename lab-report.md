# C++ Lab 2
## Exercise 1: Eratosthenes Sieve
1. learn how to declare array. easy.
2. Learn how to return array from method because I want my code clean. Less easy
- Method one: std::array. My VSC complains when I try to use it as a return-type in my header file. *Editor's Note: I have learned that this probably doesn't count as a C-style array, which the assignment asks for.*
- Method two: Pointers. ugh.
- Method three: Structs. No. We're going back to pointers.

*I cant name my `int` variable `size` for some reason. It becomes "ambiguous"* :( <!-- *I wish I was ambiguous...* -->

Why can't you make an array using an int passed through a parameter :weary: It HAS to be a constant??? I guess it's time to hard-code values 🫠

```c++
int* Program::GetPrimesLessThan(int quantity)
{
    int numbers[quantity];
}
```
`the value of parameter cannot be used as a constant`