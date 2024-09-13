# C++ Lab 2
## Exercise 1: Eratosthenes Sieve
1. learn how to declare array. easy.
2. Learn how to return array from method because I want my code clean. Less easy
- Method one: std::array. My VSC complains when I try to use it as a return-type in my header file. *Editor's Note: I have learned that this probably doesn't count as a C-style array, which the assignment asks for.*
- Method two: Pointers. ugh.
- Method three: Structs. No. We're going back to pointers[^1].

*I cant name my `int` variable `size` for some reason. It becomes "ambiguous"* :( <!-- *I wish I was ambiguous...* -->

Why can't you make an array using an int passed through a parameter :weary: It HAS to be a constant??? I guess it's time to hard-code values 🫠 

```c++
int* Program::GetPrimesLessThan(int quantity)
{
    int numbers[quantity];
}
```
"`the value of parameter cannot be used as a constant`".

*Edit: I ran into a method using dynamic memory allocation (`malloc`) to create a new array in a method. I'm not touching that. I'm reading about Vector use too. I've also come across  There's also this funny reoccuring theme I've come across in my research that reads:* ***Why To Avoid C-Arrays*** 🙂 *C++ methods like `std::vector` and `std::array` seem to be C-style arrays, except wrapped in a class that includes basic functionalities.*

Found out about dynamic-allocation-something 😃 that lookes like this: `int* var = new int[size];` This could work! I made my method return a c-array 🤩
> [!WARNING]
> REMEMBER TO `DELETE [] VAR` AT SOME POINT WHEN DOING THIS. (OR ELSE MEMORY LEAK?)

3. What do you mean by "**stryk ut** från listan alla jämna tal [...]"? I don't think the size of the array can be changed... *I'm just going to ignore the even numbers.*

The actual implementation now that I sufficiently grasp the language was fairly simple; the struggle was linear. A few moments of staring at this gif did the trick:
<a href="https://en.wikipedia.org/wiki/File:Animation_Sieve_of_Eratosth.gif"><image alt="A gif demonstrating the Sieve of Eratosthenes algorithm" src="https://upload.wikimedia.org/wikipedia/commons/9/94/Animation_Sieve_of_Eratosth.gif"></image></a>[^2]

[^1]: https://www.digitalocean.com/community/tutorials/return-array-in-c-plus-plus-function
[^2]: https://en.wikipedia.org/wiki/Sieve_of_Eratosthenes