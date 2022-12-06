<h1 align="center"> 👨🏻‍💻 Matrix Calculator </h1>

<h2 align="center">Just assignment from Parallel Computing lecture 🫥</h2>

<div align="center" style="height: ">
  <img src="https://github.com/aabduvak/matrix-calculator/assets/matrix.gif">
</div>

## Rules:
1. All matrixes must be square: [7][7], [4][4] or [2][2]
2. Bigger matrix must be first argument
3. Content of matrix must be numeric value

## Functions ##

Only the following functions are used in this project:<br>
| Function | Description | Function | Description |
|----------|-------------|----------|-------------|
| atoi | convert ascii to integer | pthread_create | create a new thread |
| printf | format and print data | pthread_mutex_unlock | releases the mutex object |
| calloc | allocate dynamic memory | pthread_join | join with a terminated thread |
| free | free dynamic memory | pthread_mutex_init | initialise the mutex |
| write | write to a file descriptor | pthread_mutex_destroy | destroy the mutex object |
| usleep | suspend execution for microsecond intervals | pthread_mutex_lock | lock the mutex object |

## Starting ##
Clone this project and change directory
```bash
git clone https://github.com/aabduvak/matrix-calculator && cd matrix-calculator
```
To compile the program you may use **Makefile**
if your linux os doesn't have **make** package just run setup.sh

```bash
bash setup.sh
```

After installation of all packages you may use make command to compile the project 
```bash
make
```
To run program
```bash
./matrix data/m1.mx data/m0.mx
```
or just use **Makefile** with default params
```bash
make run
```
Some usefull commands:
```bash
# To remove objects
make clean

# To remove objects and executable
make fclean

# To check data races
make test

# To check memory leaks
make leaks
```

## Links ##
- [pthreads Tutorial](https://randu.org/tutorials/threads/)
- [Playlist about C Threads](https://www.youtube.com/watch?v=d9s_d28yJq0&list=PLfqABt5AS4FmuQf70psXrsMLEDQXNkLq2)
- [pthreads Short Introduction](https://www.youtube.com/watch?v=d9s_d28yJq0)
- [How to pass arguments to threads](https://www.youtube.com/watch?v=HDohXvS6UIk)
- [What are detached threads?](https://www.youtube.com/watch?v=-i8Kzuwr4T4)
- [An Application of Pthreads and Mutexes](http://files.kipr.org/gcer/2009/proceedings/Myers_ApplicationPthreads.pdf)
- [Multithreading part 1](https://www.youtube.com/watch?v=GNw3RXr-VJk)
- [Multithreading part 2](https://www.youtube.com/watch?v=sDLQWivf1-I)

---
[!["Buy Me A Coffee"](https://www.buymeacoffee.com/assets/img/custom_images/orange_img.png)](https://www.buymeacoffee.com/aabduvak)
