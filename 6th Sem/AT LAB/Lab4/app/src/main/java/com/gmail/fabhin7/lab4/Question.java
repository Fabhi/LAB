package com.gmail.fabhin7.lab4;

import java.util.Arrays;
import java.util.Collections;

class Question {
    private String correctAnswer;
    String question;
    String[] answers = new String[4];

    Question(String question, String ans1, String ans2, String ans3, String ans4, String correctAnswer){
        this.question = question;
        this.answers[0] = ans1;
        this.answers[1] = ans2;
        this.answers[2] = ans3;
        this.answers[3] = ans4;
        this.correctAnswer = correctAnswer;
        shuffle();
    }

    void shuffle(){
        Collections.shuffle(Arrays.asList(answers));
    }

    String getAnswer() {
        return correctAnswer;
    }

    Boolean isCorrect(String ans){
        return correctAnswer.equals(ans);
    }


}
