                                 			1
(b).Design a responsive UI that adapts to different screen sizes.

import 'package:flutter/material.dart';

void main() =>  runApp(const MyApp());
class MyApp extends StatelessWidget {
  const MyApp({super.key});
  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      home: Scaffold(
        appBar: AppBar(title:Text("Responsive UI Example")),
        body: LayoutBuilder(
          builder: (context, constraints) {
            if (constraints.maxWidth < 600) {
              return const Center(
                child: Text("Mobile Layout", style: TextStyle(fontSize: 24)),
                );
            } else {
              return const Center(
                child: Text("Desktop Layout", style: TextStyle(fontSize: 32)),
              );
            }
          },
        ),
      ),
    );
  }
}
_____________________________________________________________________________________
							2
(a).Explore various Flutter widgets (Text, Image, Container, etc.).

import 'package:flutter/material.dart';

void main() => runApp(MyApp());

class MyApp extends StatelessWidget {
  const MyApp({super.key});

  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      home: Scaffold(
        body: Column(
          children: [
            Text('Hello Flutter!'),
            Image.network(
              'https://flutter.dev/images/flutter-logo-sharing.png',
              height: 80,
            ),
            Container(
              padding: EdgeInsets.all(10),
              color: Colors.amber,
              child: Text('Inside Container'),
            ),
          ],
        ),
      ),
    );
  }
}
__________________________________
(b).Write a program that asks the user how many Fibonacci numbers to generate and then generates them [use functions].

import 'dart:io';
void main() {
stdout.write('Enter count: ');
int n = int.parse(stdin.readLineSync()!);
fib(n);
}
void fib(int n) {
int a = 0, b = 1;
for (int i = 0; i < n; i++) {
stdout.write('$a ');
int c = a + b;
a = b;
b = c;
}
}
_____________________________________________________________________________________
							3
(a).Implement different layout structures using Row, Column, and Stack widgets.

Row:

import 'package:flutter/material.dart';

void main() {
  runApp(MyApp());
}

class MyApp extends StatelessWidget {
  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      home: Scaffold(
        appBar: AppBar(title: Text('Row Layout')),
        body: Row(
          mainAxisAlignment: MainAxisAlignment
              .spaceEvenly, 
          children: <Widget>[
            Container(color: Colors.red, width: 100, height: 100),
            Container(color: Colors.green, width: 100, height: 100),
            Container(color: Colors.blue, width: 100, height: 100),
          ],
        ),
      ),
    );
  }
}

Column:

import 'package:flutter/material.dart';

void main() {
  runApp(MyApp());
}

class MyApp extends StatelessWidget {
  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      home: Scaffold(
        appBar: AppBar(title: Text('Column Layout')),
        body: Column(
          mainAxisAlignment: MainAxisAlignment
              .spaceEvenly, 
          children: <Widget>[
            Container(color: Colors.red, width: 100, height: 100),
            Container(color: Colors.green, width: 100, height: 100),
            Container(color: Colors.blue, width: 100, height: 100),
          ],
        ),
      ),
    );
  }
}

Stack:

import 'package:flutter/material.dart';

void main() {
  runApp(const MyApp());
}

class MyApp extends StatelessWidget {
  const MyApp({Key? key}) : super(key: key);
  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      home: Scaffold(
        appBar: AppBar(title: const Text('Stack Layout')),
        body: Center(
          child: Stack(
            alignment: Alignment.center,
            children: <Widget>[
              Container(color: Colors.red, width: 200, height: 200),
              Container(color: Colors.green, width: 150, height: 150),
              Container(color: Colors.blue, width: 100, height: 100),
            ],
          ),
        ),
      ),
    );
  }
}

__________________________________
(b).Learn about stateless widgets.

import 'package:flutter/material.dart'; 
void main() => runApp(const MaterialApp(home: MyStatelessWidget())); 
class MyStatelessWidget extends StatelessWidget { 
  const MyStatelessWidget({super.key}); 
  @override 
  Widget build(BuildContext context) { 
    return Scaffold( 
      appBar: AppBar(title: const Text('Stateless Widget')), 
      body: const Center( 
        child: Text('Hello, I am a stateless widget!'), 
      ), 
    ); 
  } 
}
_____________________________________________________________________________________
							4
(a).Set up navigation between different screens using Navigator.


import 'package:flutter/material.dart';

void main() {
  runApp(NavigationDemoApp());
}
class NavigationDemoApp extends StatelessWidget {
  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      title: 'Navigation Named Routes Demo',
      initialRoute: '/',
      routes: {
        '/':(context) => HomeScreen(),
        '/second':(context) => SecondScreen(),
      },
    );
  }
}
class HomeScreen extends StatelessWidget {
  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(title: Text('Home Screen')),
      body: Center(
        child: ElevatedButton(
          child: Text('Go to Second Screen'),
          onPressed: () {
            Navigator.pushNamed(context, '/second');
          },
        ),
      ),
    );
  }
}
class SecondScreen extends StatelessWidget {
  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(title: Text('Second Screen')),
      body: Center(
        child: ElevatedButton(
          child: Text('Go to Home'),
          onPressed: () {
            Navigator.pop(context);
          },
        ),
      ),
    );
  }
}
__________________________________
(b).Create a program to ask the user for a string and print out whether this string is a palindrome or not.

import 'dart:io';
void main() {
stdout.write('Enter a string: ');
String str = stdin.readLineSync()!;
String rev = str.split('').reversed.join('');
if (str == rev) {
print('Palindrome');
} else {
print('Not Palindrome');
}
}
_____________________________________________________________________________________
							5
(a).Implement navigation with named routes.


import 'package:flutter/material.dart';

void main() {
  runApp(NavigationDemoApp());
}
class NavigationDemoApp extends StatelessWidget {
  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      title: 'Navigation Named Routes Demo',
      initialRoute: '/',
      routes: {
        '/':(context) => HomeScreen(),
        '/second':(context) => SecondScreen(),
      },
    );
  }
}
class HomeScreen extends StatelessWidget {
  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(title: Text('Home Screen')),
      body: Center(
        child: ElevatedButton(
          child: Text('Go to Second Screen'),
          onPressed: () {
            Navigator.pushNamed(context, '/second');
          },
        ),
      ),
    );
  }
}
class SecondScreen extends StatelessWidget {
  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(title: Text('Second Screen')),
      body: Center(
        child: ElevatedButton(
          child: Text('Go to Home'),
          onPressed: () {
            Navigator.pop(context);
          },
        ),
      ),
    );
  }
}
__________________________________
(b).Create a program to ask the user for a number. Depending on whether the number is even or odd, print out an appropriate message to the user.

import 'dart:io';
void main() {
stdout.write('Enter a number: ');
int n = int.parse(stdin.readLineSync()!);
if (n % 2 == 0) {
print('Even Number');
} else {
print('Odd Number');
}
}
_____________________________________________________________________________________
							6
(a).Apply styling using themes and custom styles.

import 'package:flutter/material.dart';

void main() => runApp(MyApp());

class MyApp extends StatelessWidget {
  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      theme: ThemeData(
        primarySwatch: Colors.pink,
        textTheme: const TextTheme(
          bodyMedium: TextStyle(fontSize: 22, fontWeight: FontWeight.bold),
        ),
        elevatedButtonTheme: ElevatedButtonThemeData(
          style: ElevatedButton.styleFrom(backgroundColor: Colors.pink),
        ),
      ),
      home: H(),
    );
  }
}

class H extends StatelessWidget {
  @override
  Widget build(BuildContext c) {
    return Scaffold(
      appBar: AppBar(title: Text("Theme Demo")),
      body: Center(
        child: Column(
          mainAxisSize: MainAxisSize.min,
          children: [
            Text("Styled Text!", style: Theme.of(c).textTheme.bodyMedium),
            ElevatedButton(onPressed: () {}, child: Text("Styled Button")),
          ],
        ),
      ),
    );
  }
}
__________________________________
(b).Create a program that asks the user for a number and then prints out a list of all the divisors of that number.

import 'dart:io';
void main() {
stdout.write('Enter a number: ');
int n = int.parse(stdin.readLineSync()!);
stdout.write('Divisors: ');
for (int i = 1; i <= n; i++) {
if (n % i == 0) stdout.write('$i ');
}
}
_____________________________________________________________________________________
							7
(a).Add animations to UI elements using Flutter's animation framework.

import 'package:flutter/material.dart';

void main() => runApp(MaterialApp(home: A()));

class A extends StatefulWidget {
  @override
  State<A> createState() => _S();
}

class _S extends State<A> {
  double s = 100;

  @override
  Widget build(BuildContext c) {
    return Scaffold(
      appBar: AppBar(title: Text("Animation Demo")),
      body: Center(
        child: GestureDetector(
          onTap: () => setState(() => s = s == 100 ? 180 : 100),
          child: AnimatedContainer(
            duration: Duration(seconds: 1),
            width: s,
            height: s,
            color: Colors.purple,
          ),
        ),
      ),
    );
  }
}

__________________________________
(b).Create a program that asks the user to enter their name and their age. Print out a message that tells how many years they have to be 100 years old.

import 'dart:io';
void main() {
stdout.write("Enter your name: ");
String name = stdin.readLineSync()!;
stdout.write("Enter your age: ");
int age = int.parse(stdin.readLineSync()!);
int years = 100 - age;
print("$name, you will be 100 years old in $years years!");
}
