# VIT SEARCH

VIT is a marvelous university with diverse population and abundant talent, it sure is a giant leap for us from our backgrounds. 
<br> 
<br>
But there's a catch! There are a lot of people, this might be a good thing for us scholars, but it sure is tedious when you want to find a person's details given their registration number!
<br>
<br>
Linear search will work, but it'll be tedious to search every single string over and over again! Binary search will work better as we can store all the registration numbers in a sorted manner and use that, but still we can do better. 
<br>
<br>
Hashing is plausible but still for sizes in thousands upon thousands, we have to do better! And that's where tries come into picture and in this project, I'll be using Tries to solve to problem of searching VITians!
<br>
<br>
The main objective of the project is to insert the details of VITians and search them, the details however aren't going to persist, I do however wish to find a way to persist data in the future, either by using a file or in a database (locally) or in the cloud.

## IMPROVEMENTS TO BE MADE
- Rewriting the whole project without `using namespace std;` as it destroyes the purpose of namespace.
- The data fields of `VitianNode` are public, which is not desirable in the long run, they should be made private with necessary getters and setters (or putters).
- Using regular expression to verify whether the string entered by the client is correct (VIT uses a 9 Letter system, where the first two characters are the year of joining, next three is the course undertaken and last 4 is the number, for instance, Ex: 20BCE0138)
- Ability to batch insert multiple students by reading from a file or from a cloud storage would be desirable too. In addition to that using a cloud platform to store all the VITians data in the form of blobs with indexed web-links is an approach I'm willing to look into.