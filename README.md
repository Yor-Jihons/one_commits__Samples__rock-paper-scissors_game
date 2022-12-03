# one_commits__Samples__rock-paper-scissors_game

This is a sample so that I can commit this to the GitHub.

## 1. Question

ユーザの手をuser_hand, コンピュータの手をcomputer_handとし、じゃんけんゲームをするプログラムを組め。
user_handとcomputer_handはそれぞれ{ R, P, S }のいずれかの一文字とし、N回戦を行いユーザの勝敗数を表示せよ。

## 2. Conditions

1≦N≦10
user_hand{i} = { 'R' | 'P' | 'S' }
computer_hand{i} = { 'R' | 'P' | 'S' }

## 3. Inputs and Outputs

### 3.1. Inputs

```
N
user_hand1 computer_hand1
user_hand2 computer_hand2
user_hand3 computer_hand3
```

一行目にじゃんけんの回数が渡される。
二行目以降は順にユーザとコンピュータのそれぞれの手が半角スペースを栗木文字として渡される。

### 3.2. Outputs

```
Win : W
Lose: L
Draw: D
```

一行目に"Win : " という文字列の直後にユーザが勝った回数を、
二行目に"Lose: " という文字列の直後にユーザが負けた回数を、
三行目に"Draw: " という文字列の直後にあいこの回数を出力する。


### 3.3. Examples

#### 3.3.1. Inputs 1

```
7
R P
R S
S S
P S
S P
P R
P P
```
#### 3.3.2. Outputs 1

```
Win : 3
Lose: 2
Draw: 2
```

※ Inputs 1 は input1.txt, Output 1 は output1.txt に記述されているとする。
