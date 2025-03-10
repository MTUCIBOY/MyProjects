# Team 00 — Go Boot camp

## Randomaliens

💡 [Tap here](https://new.oprosso.net/p/4cb31ec3f47a4596bc758ea1861fb624) **to leave your feedback on the project**. It's anonymous and will help our team make your educational experience better. We recommend completing the survey immediately after the project.

## Contents

1. [Chapter I](#chapter-i) \
    1.1. [General rules](#general-rules)
2. [Chapter II](#chapter-ii) \
    2.1. [Rules of the day](#rules-of-the-day)
3. [Chapter III](#chapter-iii) \
    3.1. [Intro](#intro)
4. [Chapter IV](#chapter-iv) \
    4.1. [Task 00: Transmitter](#exercise-00-transmitter)
5. [Chapter V](#chapter-v) \
    5.1. [Task 01: Anomaly Detection](#exercise-01-anomaly-detection)
6. [Chapter VI](#chapter-vi) \
    6.1. [Task 02: Report](#exercise-02-report)
7. [Chapter VII](#chapter-vii) \
    7.1. [Task 03: All Together](#exercise-03-all-together)
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

- You should only print `\*.go`, `\*_test.go` and (in case of external dependencies) `go.mod` + `go.sum` files.
- Your code for this task should be buildable with just `go build`.
- All your tests should be executable with the standard `go test ./...` call.

<h2 id="chapter-iii" >Chapter III</h2>
<h2 id="intro" >Intro</h2>

"We have no idea how to do this!" Louise was almost desperate. "The ship keeps changing frequencies!"

It was the second sleepless night in a row for her. Everything pointed to aliens trying to communicate with Earthlings, but the main problem was understanding each other.

The radio on the table suddenly woke up: "Halpern reporting. Our agents have attached a coding device to the ship. It collects the generated frequencies and can send them in binary over the network."

Louise immediately rushed to the nearest screen, but apparently the device only transmitted within an encrypted military network to which none of the science crew had access.

A brilliant linguist was a pity to watch. But after a few minutes, she shook her head, as if to dispel some thoughts, and began angrily negotiating with the military over the radio. At the same time, her hand was furiously scribbling notes on a piece of paper.

After about half an hour, she sank wearily into a chair and threw the radio on the table. Then she looked up at the team.

"Does anyone here know how to program?" She asked. "These morons won't give us access to their device. So we'll have to create something similar, and then they'll agree to put our analyzer into their network. But only if we test it first!"

Two or three hands went up uncertainly.

"Okay, so it uses something called gRPC, whatever that means. Our analyzer was supposed to connect to it and receive a stream of frequencies to look at and generate some kind of report in PostgreSQL. You gave me a data format."

She stood up and paced a bit.

"I understand that analyzing a completely random signal is a difficult task. I wish we had more information."

And then the radio came on again. And what Louise heard made her eyes light up with excitement. She looked at the team and said one more thing in a loud, triumphant whisper:

"I think I know what to do! IT'S NORMALLY DISTRIBUTED!"

<h2 id="chapter-iv" >Chapter IV</h2>
<h3 id="ex00">Task 00: Transmitter</h3>

"So we have to reimplement the protocol of this military device on our own." Louise said. "I already mentioned that it uses gRPC, so let's do that."

She showed a basic schematic of the data types. It looks like each message consists of just three fields — 'session_id' as a string, 'frequency' as a double, and also a current timestamp in UTC.

We don't know much about the distribution here, so let's implement it so that each time a new client connects, [expected value](https://en.wikipedia.org/wiki/Expected_value) and [standard deviation](https://en.wikipedia.org/wiki/Standard_deviation) are randomly chosen. For this experiment, let's pick the mean from the interval [-10, 10] and the standard deviation from [0.3, 1.5].

On each new connection, the server should generate a random UUID (sent as session_id) and new random values for mean and STD. All generated values should be written to a server log (stdout or file). Then it should send a stream of entries with the fields explained above, where for each message 'frequency' would be a value randomly sampled from a normal distribution with this standard deviation and expected value.

It is necessary to describe the scheme in a *.proto* file and generate the code from it. Also, you shouldn't modify the generated code manually, just import it.

<h2 id="chapter-v" >Chapter V</h2>
<h3 id="ex01">Task 01: Anomaly Detection</h3>

"Now for the interesting part! While others are working on the gRPC server, let's think about a client. I expect that the gRPC client should be handled by the same people writing the server to test it, so let's focus on something else. We need to find anomalies in a frequency distribution!"

So you know you're getting a stream of values. With each new incoming entry from a stream, your code should be able to approximate the mean and STD from the random distribution generated on a server. Of course, it's not really possible to predict them if you're only looking at 3-5 values, but after 50-100 it should be accurate enough. Keep in mind that mean and STD are generated for each new connection, so you shouldn't restart the client during the process. Also, you don't want the values to pile up in memory, so you might consider using sync.Pool for easy reuse.

While working on this task, you can temporarily forget about gRPC and test the code by simply sending it a sequence of values to stdin.

Your client code should periodically write to a log how many values have been processed so far, as well as the predicted values of mean and STD.

After some time, when your client decides that the predicted distribution parameters are good enough (feel free to choose this time yourself), it should automatically switch to an anomaly detection stage. Here another parameter comes into play — an *STD anomaly coefficient*. So your client should accept a command line parameter (let's say '-k') with a float coefficient.

An incoming frequency is considered an anomaly if it differs from the expected value by more than *k \* STD* on any side (left or right, since the distribution is symmetric). You can read more about how this works by following the links in Chapter 4.

For now, you should just log the anomalies you find.

<h2 id="chapter-vi" >Chapter VI</h2>
<h3 id="ex02">Task 02: Report</h3>

"Since the general doesn't know anything about our *science gizmo*, let's store all the anomalies we encounter in a database and then he'll be able to look at them through some interface they have," Louise seems to be much more concerned about the data than the general.

So, let's learn how to write data entries in PostgreSQL. Usually it is considered bad practice to just write plain SQL queries in code when dealing with high security environments (you can read about SQL injections by following the links from Chapter 4). Let's use an ORM. In the case of PostgreSQL, there are two most obvious choices (these links are also below), but you can choose any other. The main idea here is not to have strings of SQL code in your source.

You'll need to describe your entry (session_id, frequency and a timestamp) as a structure in Go and then use it together with the ORM to map it to database columns.

<h2 id="chapter-vii" >Chapter VII</h2>
<h3 id="ex03">Task 03: All Together</h3>

Okay, so once we have a transmitter, receiver, anomaly detection, and ORM, we can plug things together and merge them into a complete project.

So if you start a server and a client (PostgreSQL should already be running on your machine), your client will connect to a server and get a stream of entries, which it will then use for:

- First, use them for a distribution reconstruction (mean/STD).
- Second, after some time, start detecting anomalies based on the provided STD anomaly coefficient (I suggest you choose it big enough for this experiment, so that anomalies don't occur too often).
- Third, all anomalies should be written to a database in PostgreSQL using ORM.

If Louise is right, these anomalies could be the key to first contact with aliens. But it is also a pretty direct approach for cases where you need to detect anomalies in a data stream, for which Go can be used efficiently.

<h2 id="chapter-viii" >Chapter VIII</h2>
<h3 id="reading">Reading</h3>

- [Normal distribution](https://en.wikipedia.org/wiki/Normal_distribution).
- [68-95-99.7 rule](https://en.wikipedia.org/wiki/68%E2%80%9395%E2%80%9399.7_rule).
- [SQL Injections](https://en.wikipedia.org/wiki/SQL_injection).
- [go-pg](https://github.com/go-pg/pg).
- [GORM](https://gorm.io/index.html).


