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

*Edit: I ran into a method using dynamic memory allocation (`malloc`) to create a new array in a method. I'm not touching that. I'm reading about Vector use too. I've also come across  There's also this funny reoccurring theme I've come across in my research that reads:* ***Why To Avoid C-Arrays*** 🙂 *C++ methods like `std::vector` and `std::array` seem to be C-style arrays, except wrapped in a class that includes basic functionalities.*

Found out about dynamic-allocation-something 😃 that looks like this: `int* var = new int[size];` This could work! I made my method return a c-array 🤩
> [!WARNING]
> REMEMBER TO `DELETE [] VAR` AT SOME POINT WHEN DOING THIS. (OR ELSE MEMORY LEAK?)

3. What do you mean by "**stryk ut** från listan alla jämna tal [...]"? I don't think the size of the array can be changed... *I'm just going to ignore the even numbers by marking them with a bool.*

The actual implementation now that I sufficiently grasp the language was fairly simple; the struggle was linear. A few moments of staring at this gif did the trick:
<a href="https://en.wikipedia.org/wiki/File:Animation_Sieve_of_Eratosth.gif" target="_blank"><image style="width" alt="A gif demonstrating the Sieve of Eratosthenes algorithm" src="https://upload.wikimedia.org/wikipedia/commons/9/94/Animation_Sieve_of_Eratosth.gif"></image></a>[^2]

I've just attended the lecture explaining pointers... things are making a little more sense. `&` denotes a reference to memory. A `*` pointer "points" to the content of a reference (but stores the memory address... if assigned with a reference variable... I think)? What does it mean to say `int *value = 5` then?

For some reason I can't assign a default value of zero to the `lowerBound` parameter in the `GetPrimes` method... 🤔

`'Program::GetPrimes': redefinition of default argument: parameter 1`

For whatever reason, `sizeof(numbers)` (my array) is always equal to `4`  and `sizeof(numbers[0])` is also always equal to `4` (as expected, this time). Why is `sizeof(numbers) = 4`??? I can clearly in the debugger see that each value from `numbers[0]` and `numbers[13]` equals 0 to 13, respectively. What?? Update: I got it to work, but I had to hardcode the arraysize in the `PrintNumbers` for-loop.

### 2 October 2024
**ChatGPT** now tells me that "There's no way to determine the size of the dynamically allocated memory using `sizeof` because it only gives the size of the pointer" and that I should "always store the size in a separate variable when you create the array" when you create dynamically allocated arrays. This is an issue. Now I want to create a struct for my c-style arrays, what the heck. *This is why we use `std::string`* :)

There is apparently a **key** difference between `char cstring[]` and `char *cstring` 🫠 During lectures I was under the impression that arrays were *always* just pointers pointing to the first element in the array—and maybe they are under the hood? But apparently arrays are their own data type whose length is calculatable using `sizeof`. The length of `char *cstring`, however, will always return `4` because that's the size of the `pointer` data type.[^3][^4] Now I don't know how the heck to get the size of my c-style arrays. 

> [!IMPORTANT]
> I think differences likes this could have been better explained in lectures if we discussed more practical (and realistic) implementations of pointers, including at least rough examples of *how we are expected to use them* in upcoming assignments.

I gave up and used the `<cstring>` library to get the length of my `char *cstring`s (using `strlen`). All I remember being told is that we were supposed to use c-style arrays and c-strings, and the instructions do not touch on whether such libraries are legal. Would've loved to know that before all this struggle.

> [!NOTE]
> This still wouldn't solve my problem of not knowing the length of my `int *numbers` array. Maybe there's a library for that too? But whatever—everyone uses `std:array` anyway 🙄

I stumbled into a write access violation and declared my `char*`s onto the heap (`char *source = new char[] {...}`) instead. Also, I had to change `source[i + k] = find[k];` to `source++; *source = replace[k];` (now using dereference) for any change to actually occur.

<!------------------------------------------------------------->

[^1]: https://www.digitalocean.com/community/tutorials/return-array-in-c-plus-plus-function
[^2]: https://en.wikipedia.org/wiki/Sieve_of_Eratosthenes
[^3]: https://www.naukri.com/code360/library/whats-the-difference-between-char-s-and-char-s-in-c
[^4]: https://stackoverflow.com/questions/7564033/difference-between-char-and-char