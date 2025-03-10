# Day 05 — Go Boot camp

## Santa is back in town 

💡 [Tap here](https://new.oprosso.net/p/4cb31ec3f47a4596bc758ea1861fb624) **to leave your feedback on the project**. It's anonymous and will help our team make your educational experience better. We recommend completing the survey immediately after the project.

## Contents

1. [Chapter I](#chapter-i) \
    1.1. [General rules](#general-rules)
2. [Chapter II](#chapter-ii) \
    2.1. [Rules of the day](#rules-of-the-day)
3. [Chapter III](#chapter-iii) \
    3.1. [Intro](#intro)
4. [Chapter IV](#chapter-iv) \
    4.1. [Exercise 00: Toys on a Tree](#exercise-00-toys-on-a-tree)
5. [Chapter V](#chapter-v) \
    5.1. [Exercise 01: Decorating](#exercise-01-decorating)
6. [Chapter VI](#chapter-vi) \
    6.1. [Exercise 02: Heap of Presents](#exercise-02-heap-of-presents)
7. [Chapter VII](#chapter-vii) \
    7.1. [Exercise 03: Knapsack](#exercise-03-knapsack)
8. [Chapter VIII](#chapter-viii) \
    8.1. [Reading](#reading)


<h2 id="chapter-i" >Chapter I</h2>
<h2 id="general-rules" >General rules</h2>

- Your programs should not exit unexpectedly (give an error on valid input). If this happens, your project will be considered non-functional and will receive a 0 in the evaluation.
- We encourage you to create test programs for your project, even though this work doesn't have to be submitted and won't be graded. This will allow you to easily test your work and the work of your peers. You will find these tests particularly useful during your defense. In fact, you are free to use your tests and/or the tests of the peer you are evaluating during your defense.
- Submit your work to your assigned git repository. Only the work in the git repository will be evaluated.
- If your code uses external dependencies, it should use [Go Modules](https://go.dev/blog/using-go-modules) to manage them.

<h2 id="chapter-ii" >Chapter II</h2>
<h2 id="rules-of-the-day" >Rules of the Day</h2>

- You should only submit `*.go` files and (in case of external dependencies) `go.mod` + `go.sum`.
- Your code for this task should be buildable with just `go build`.

<h2 id="chapter-iii" >Chapter III</h2>
<h2 id="intro" >Intro</h2>

"I don't know," said Lily. "The only thing I read about this thing that old dudes call 'Christmas' is that you are supposed to have a tree, something called a 'garland', and finally a 'heap of presents', whatever that means.

You move the Neuralink visor down to your neck.

"Come on, girl, that's just an urban legend! Why do you think a combination of such basic things would result in anything interesting?"

She looked up at the ceiling and dreamed.

"There was this, like, old guy in a red hoodie or something... Do you think he was one of the first Rebellion hackers? You know, sharing quick hacks with everyone? So if the script kiddies were excited about freedom and fighting the Corpos, they could use their 'presents' to breach corporate firewalls?"

"Yeah, seems legit. Urban legends of the underground tend to have that mystical aura, you know. Most likely it was just some bearded open source enthusiast. As crazy as people are these days, at least nobody's saying "he rode an antigravity sleigh pulled by robot reindeer". It's more likely that he had a botnet of portable [ELF](https://en.wikipedia.org/wiki/Executable_and_Linkable_Format) binaries on corporate servers, collecting secret stuff to give away for free."

Lily leaned back on the couch and pulled up a bunch of holograms.

"Okay, so everyone knows what trees look like — a bunch of 3d graphs with no cycles floated over her head — which one do we need?"

<h2 id="chapter-iv" >Chapter IV</h2>
<h3 id="ex00">Exercise 00: Toys on a Tree</h3>

After some time, you two put together a structure for a [Binary tree](https://en.wikipedia.org/wiki/Binary_tree) node:

```go
type TreeNode struct {
    HasToy bool
    Left *TreeNode
    Right *TreeNode
}
```

"Looks like you should... 'hang toys' on trees?" Lily looked a little confused. "Okay, anyway, let's hope a boolean value will suffice. But you also say it's wrong to put more toys on one side, should it be even?"

"Okay, I get it," you said. "Let's write a function `areToysBalanced` that takes a pointer to a tree root as an argument. The point is to spit out a true/false boolean value depending on whether the left subtree has the same amount of toys as the right one. The value on the root itself can be ignored."

So your function should return `true` for such trees (0/1 representing false/true, equal amount of 1's on both subtrees):

```
    0
   / \
  0   1
 / \
0   1
```

```
    1
   /  \
  1     0
 / \   / \
1   0 1   1
```

and `false` for such trees (non-equal amount of 1's on both subtrees):

```
  1
 / \
1   0
```

```
  0
 / \
1   0
 \   \
  1   1
```

<h2 id="chapter-v" >Chapter V</h2>
<h3 id="ex01">Exercise 01: Decorating</h3>

"Now, about this 'garland'... It is supposed to be 'reeled up' on a tree."

Lily turns the hologram back and forth, trying to think of something. Then she suddenly lights up with enthusiasm.

"I got it! Let's do it like this..." She draws something that looks like a 3D snake on top of the tree.

So now you need to write another function called `unrollGarland()`, which also takes a pointer to a root node. The idea is to go top down, layer by layer, going right on even horizontal layers and left on odd horizontal layers. The return value of this function should be a slice of bools. So, for this tree:

```
    1
   /  \
  1     0
 / \   / \
1   0 1   1
```

The answer will be [true, true, false, true, true, false, true] (root is true, then on second level we go from left to right, and then on third from right to left, like a zig-zag).

<h2 id="chapter-vi" >Chapter VI</h2>
<h3 id="ex02">Exercise 02: Heap of Presents</h3>

"Perfect! I have no idea what those old guys meant by 'Christmas tree', but I think we've got the general requirements covered."

"Now, about those 'presents'..."

"Presents, right!" Lily lifts her elegant finger with a very long purple nail. It has been specially strengthened for fighting enemies and (much more often) for unscrewing various devices. "So let's think of it as a stack. Any such 'present' might look like this:"

```go
type Present struct {
    Value int
    Size int
}
```

"Hmm, what is 'value'?"

"Well, some things you tend to value more than others, right? So they should be comparable."

"Okay, and 'Size' is about how long it will take me to download it, right?"

"Exactly! So the coolest stuff should be on top."

You need to implement a PresentHeap data structure (using the built-in "container/heap" library is recommended, but not required). Presents are compared by Value first (most valuable present goes on top of the heap). *Only* if two Presents have the same Value, the smaller one is considered "cooler" than the other (wins the comparison).

Apart from the structure itself, you should implement a function `getNCoolestPresents()` which, given an unsorted slice of presents and an integer `n`, returns a sorted slice (desc) of the "coolest" ones from the list. It should use the PresentHeap data structure inside and return an error if `n` is greater than the size of the slice or is negative.

So if we represent each present by a tuple of two numbers (Value, Size), then for this input:

```
(5, 1)
(4, 5)
(3, 1)
(5, 2)
```

The two "coolest" presents would be [(5, 1), (5, 2)] because the first one has the smaller size of the two with value = 5.

<h2 id="chapter-vii" >Chapter VII</h2>
<h3 id="ex03">Exercise 03: Knapsack</h3>

"Wait!" you said. "But how do I know that all these amazing presents won't take up all the space on my hard drive?"

Lily thought for a moment, but then suggested:

"Just in case, let's only download the most valuable presents!"

"But the heap uses a different order and won't help us here..."

"True, true. Anyway, there should be some argument to figure out how to get the most value out of the space you have, right?"

...It was a great winter night in CyberCity. Even though the traditions had changed a lot in the past centuries, you two had the feeling that you were doing everything right. Lily didn't know about the cool new portable Cyberdeck you had prepared as a gift for her. And you had no idea what was in that mysterious little box on her desk.

As a final task, you have to implement a classic dynamic programming algorithm, also known as the "Knapsack problem". The input is almost the same as in the last task — you have a slice of Presents, each with a Value and Size, but this time you also have a hard drive with a limited capacity. So you need to select only those presents that fit into that capacity and maximize the resulting value.

Write a function `grabPresents()` that takes a slice of the present instances and a capacity of your hard drive. As an output, this function should return another slice of Presents, which should have a maximum cumulative Value that you can get with such capacity.

<h2 id="chapter-viii" >Chapter VIII</h2>
<h3 id="reading">Reading</h3>

- [Binary Tree](https://en.wikipedia.org/wiki/Binary_tree).
- [Breadth-First Search](https://en.wikipedia.org/wiki/Breadth-first_search).
- [Depth-First Search](https://en.wikipedia.org/wiki/Depth-first_search).
- [Recursion in Go](https://www.tutorialspoint.com/go/go_recursion.htm).
- [Heap](https://en.wikipedia.org/wiki/Heap_(data_structure)).
- [Heap implementation in Go](https://golang.org/pkg/container/heap/).
- [Knapsack Problem](https://en.wikipedia.org/wiki/Knapsack_problem).
- [Multi-Dimensional arrays and slices in Go](https://golangbyexample.com/two-dimensional-array-slice-golang/).

