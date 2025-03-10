# Day 04 — Go Boot camp

## Candy!

💡 [Tap here](https://new.oprosso.net/p/4cb31ec3f47a4596bc758ea1861fb624) **to leave your feedback on the project**. It's anonymous and will help our team make your educational experience better. We recommend completing the survey immediately after the project.

## Contents

1. [Chapter I](#chapter-i) \
    1.1. [General rules](#general-rules)
2. [Chapter II](#chapter-ii) \
    2.1. [Rules of the day](#rules-of-the-day)
3. [Chapter III](#chapter-iii) \
    3.1. [Intro](#intro)
4. [Chapter IV](#chapter-iv) \
    4.1. [Exercise 00: Catching the Fortune](#exercise-00-catching-the-fortune)
5. [Chapter V](#chapter-v) \
    5.1. [Exercise 01: Law and Order](#exercise-01-law-and-order)
6. [Chapter VI](#chapter-vi) \
    6.1. [Exercise 02: Old Cow](#exercise-02-old-cow)
7. [Chapter VII](#chapter-vii) \
    7.1. [Reading](#reading)


<h2 id="chapter-i" >Chapter I</h2>
<h2 id="general-rules" >General rules</h2>

- Your programs should not exit unexpectedly (give an error on valid input). If this happens, your project will be considered non-functional and will receive a 0 in the evaluation.
- We encourage you to create test programs for your project, even though this work doesn't have to be submitted and won't be graded. This will allow you to easily test your work and the work of your peers. You will find these tests particularly useful during your defense. In fact, you are free to use your tests and/or the tests of the peer you are evaluating during your defense.
- Submit your work to your assigned git repository. Only the work in the git repository will be evaluated.
- If your code uses external dependencies, it should use [Go Modules](https://go.dev/blog/using-go-modules) to manage them.

<h2 id="chapter-ii" >Chapter II</h2>
<h2 id="rules-of-the-day" >Rules of the day</h2>

- You should only submit `*.go` files and (in case of external dependencies) `go.mod` + `go.sum`.
- Your code for this task should be buildable with just `go build`.
- Although it is required not to modify the C code, you still have to comment out the `main()` function in it, otherwise the program won't compile (two entry points).

<h2 id="chapter-iii" >Chapter III</h2>
<h2 id="intro" >Intro</h2>

Mr. Rogers is very sad. He sits in your office and mumbles, "My whole business...how am I supposed to make people happy now?

This story is as old as the world. This new client of yours started a new business selling candy all over this muddy town. At first, everything was perfect — several vending machines, 5 delicious kinds of candy, and lines of children begging their parents to buy some for them. And then it was like a thunderbolt when someone broke into a data center and stole a server responsible for handling candy orders. Not only that, but an old developer went missing as well! Coincidence? You don't think so.

You pour Mr. Rogers a glass of good old bourbon and start asking questions, trying to get more details.

"Well, I don't know much. All of our vending machines were selling the same set of candies, you know, here they are on the brochure," he hands you the colorful piece of paper advertising five new amazing flavors:

```
Cool Eskimo: 10 cents
Apricot Aardvark: 15 cents
Natural Tiger: 17 cents
Dazzling 	Elderberry: 21 cents
Yellow Rambutan: 23 cents
```

"That's a weird sounding name," you say. "How do people remember these things?" 

"Oh, that's easy," said Rogers. "We use abbreviations everywhere, even in our source code. So it's CE, AA, NT, and so on." He sobs. "But does it even matter now? My business is ruined anyway. All this is just nonsense!"

"Please focus, Mr. Rogers," you've seen guys behave like this many times before, this place isn't called "Gopher PI" for nothing. "Is there anything else you didn't mention?"

"You're right! I almost forgot!" He pulls a piece of paper from his pocket and hands it to you. "The thief left a note!"

You look at the text written in marker on one side: "I can't eat any more candy!" This doesn't give you much. Then, you flip the page and...

"Okay, Mr. Rogers. The good news is, I now know for sure that it was your ex-employee who stole the server. But not only that! Something tells me I can help you rebuild your business, too."

<h2 id="chapter-iv" >Chapter IV</h2>
<h3 id="ex00">Exercise 00: Catching the Fortune</h3>

Turns out, the thief used the first piece of paper he had on his desk, and it happened to be a specification for a protocol between a vending machine and a server. It looked like this:

```yaml
---
swagger: '2.0'
info:
  version: 1.0.0
  title: Candy Server
paths:
  /buy_candy:
    post:
      consumes:
        - application/json
      produces:
        - application/json
      parameters:
        - in: body
          name: order
          description: summary of the candy order
          schema:
            type: object
            required:
              - money
              - candyType
              - candyCount
            properties:
              money:
                description: amount of money put into vending machine
                type: integer
              candyType:
                description: kind of candy
                type: string
              candyCount:
                description: number of candy
                type: integer
      operationId: buyCandy
      responses:
        201:
          description: purchase succesful
          schema:
              type: object
              properties:
                thanks:
                  type: string
                change:
                  type: integer
        400:
          description: some error in input data
          schema:
              type: object
              properties:
                error:
                  type: string
        402:
          description: not enough money
          schema:
              type: object
              properties:
                error:
                  type: string
```

Over the next few hours, Mr. Rogers told you all the details. To rebuild the server, you need to use this spec to generate a bunch of Go code that actually implements the backend part. It's possible to rewrite the whole thing manually, but in that case the thief might get away before you do, so you need to generate the code as soon as possible.

Each candy buyer puts in money, chooses what kind of candy to buy and how many to buy. This data is sent to the server via HTTP and JSON, and then:

1) If the sum of the candy prices (see Chapter 1) is less than or equal to the amount of money the buyer gave to a machine, the server responds with HTTP 201 and returns a JSON with two fields — "thanks", which says "Thank you!", and "change", which is the amount of change the machine has to give back to the customer.
2) If the amount is greater than the amount provided, the server responds with HTTP 402 and an error message in JSON that says "You need {amount} more money!", where {amount} is the difference between the amount provided and the amount expected.
3) If the client provided a negative candyCount or a wrong candyType (remember: all five candy types are encoded by two letters, so it's one of "CE", "AA", "NT", "DE" or "YR", all other cases are considered invalid), then the server should respond with 400 and an error in JSON describing what went wrong. You can actually do this in two different ways — it's either writing the code manually with these checks, or modifying the Swagger spec above so that it would cover these cases.

Remember: all data from both client and server should be in JSON, so you can test your server this way, for example:

```
curl -XPOST -H "Content-Type: application/json" -d '{"money": 20, "candyType": "AA", "candyCount": 1}' http://127.0.0.1:3333/buy_candy

{"change":5,"thanks":"Thank you!"}
```

or

```
curl -XPOST -H "Content-Type: application/json" -d '{"money": 46, "candyType": "YR", "candyCount": 2}' http://127.0.0.1:3333/buy_candy

{"change":0,"thanks":"Thank you!"}
```

Also, you don't need to keep track of the stock of different types of candy, just pretend that the machines do it for you. Just validate the user input and calculate the change.

<h2 id="chapter-v" >Chapter V</h2>
<h3 id="ex01">Exercise 01: Law and Order</h3>

You sit back and smile, feeling something that seems to be well cooked. Mr. Rogers also seems to relax a little. But then his face changes again.



"I know we've already paid for increased security at our data center," he said, a bit thoughtfully. "...but what if this criminal decides to use some [Man-in-the-middle](https://en.wikipedia.org/wiki/Man-in-the-middle_attack) trickery? My business will be destroyed again! People will lose their jobs, and I'll go bankrupt!"

"Easy there, good sir," you say with a grin. "I think I've got just what you need."

So you need to implement certificate authentication for the server, as well as a test client that can query your API using a self-signed certificate and a local security authority to "verify" it on both sides.

You already have a server that supports TLS, but it's possible that you'll need to regenerate the code to specify an additional parameter so that it will use secure URLs.

You'll also need a local certificate authority to manage certificates. For our task, [minica](https://github.com/jsha/minica) seems like a good enough solution. There is a link to a really helpful video in the last Chapter if you want to know more details about how Go works with secure connections.

Since we're talking about full-blown mutual TLS authentication, you'll need to generate two cert/key pairs — one for the server and one for the client. Minica will also generate a CA file called `minica.pem` for you, which you'll need to plug into your client somehow (your auto-generated server should already support specifying a CA file as well as `key.pem` and `cert.pem` via command line parameters). Also, certificate generation may require you to use a domain instead of an IP address, so in the examples below we will use "candy.tld".

Keep in mind that because you're using a custom local CA, you probably won't be able to query your API using cURL, a web browser, or a tool like [Postman](https://www.postman.com/) without tuning.

Your test client should support the flags '-k' (accepts a two-letter abbreviation for the candy type), '-c' (number of candies to buy), and '-m' (amount of money you "gave" to the machine). So the "purchase request" should look like this:

```
~$ ./candy-client -k AA -c 2 -m 50
Thank you! Your change is 20
```

<h2 id="chapter-vi" >Chapter VI</h2>
<h3 id="ex02">Exercise 02: Old Cow</h3>

After a few days, Mr. Rogers finally calls you with great news — the thief has been caught and immediately confessed! But the candy businessman also had a small request.

"You seem to know a lot about machines, don't you? There's one last thing I'd like you to do, which is really nothing. Our customers prefer something funny instead of just a simple 'thank you', so my nephew Patrick has written a program that generates a funny animal that says things. I think it's written in C, but that's not a problem for you, is it? Please don't change the code, Patrick is still improving it!"

Oh boy. You look through your emails and notice one from Mr. Rogers with some code attached:

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

unsigned int i;
unsigned int argscharcount = 0;

char *ask_cow(char phrase[]) {
  int phrase_len = strlen(phrase);
  char *buf = (char *)malloc(sizeof(char) * (160 + (phrase_len + 2) * 3));
  strcpy(buf, " ");

  for (i = 0; i < phrase_len + 2; ++i) {
    strcat(buf, "_");
  }

  strcat(buf, "\n< ");
  strcat(buf, phrase);
  strcat(buf, " ");
  strcat(buf, ">\n ");

  for (i = 0; i < phrase_len + 2; ++i) {
    strcat(buf, "-");
  }
  strcat(buf, "\n");
  strcat(buf, "        \\   ^__^\n");
  strcat(buf, "         \\  (oo)\\_______\n");
  strcat(buf, "            (__)\\       )\\/\\\n");
  strcat(buf, "                ||----w |\n");
  strcat(buf, "                ||     ||\n");
  return buf;
}

int main(int argc, char *argv[]) {
  for (i = 1; i < argc; ++i) {
    argscharcount += (strlen(argv[i]) + 1);
  }
  argscharcount = argscharcount + 1;

  char *phrase = (char *)malloc(sizeof(char) * argscharcount);
  strcpy(phrase, argv[1]);

  for (i = 2; i < argc; ++i) {
    strcat(phrase, " ");
    strcat(phrase, argv[i]);
  }
  char *cow = ask_cow(phrase);
  printf("%s", cow);
  free(phrase);
  free(cow);
  return 0;
}
```

It looks like you need to return an ASCII cow as text in the "thanks" field in response. When querying via cURL it will look like this:

```
~$ curl -s --key cert/client/key.pem --cert cert/client/cert.pem --cacert cert/minica.pem -XPOST -H "Content-Type: application/json" -d '{"candyType": "NT", "candyCount": 2, "money": 34}' "https://candy.tld:3333/buy_candy"
{"change":0,"thanks":" ____________\n< Thank you! >\n ------------\n        \\   ^__^\n         \\  (oo)\\_______\n            (__)\\       )\\/\\\n                ||----w |\n                ||     ||\n"}

```

Apparently, all you need to do is reuse this `ask_cow()` C function without rewriting it in your Go code.

"Sometimes I think I should give up all this detective work and just work as a senior engineer," you grumble.

At the very least, you should have all the candy you want. Like, for the rest of your life.

<h2 id="chapter-vii" >Chapter VII</h2>
<h3 id="reading">Reading</h3>

[Original cowsay](https://en.wikipedia.org/wiki/Cowsay)
