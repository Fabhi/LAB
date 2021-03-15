package com.gmail.fabhin7.lab3;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.Toast;

import java.util.Random;

public class EvalActivity extends AppCompatActivity {
    static int upperbound = 11;
    int number;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_eval);
        Random rand = new Random();
        number = rand.nextInt(upperbound);

        EditText numberInput = findViewById(R.id.number_input);
        Button checkButton = findViewById(R.id.check_button);

        checkButton.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                int numb = Integer.parseInt(String.valueOf(numberInput.getText()));
                String string;
                if(numb < number) string="Too Low";
                else if(numb > number) string="Too High";
                else string="You guessed correctly!";
                Toast.makeText(getApplicationContext(), string, Toast.LENGTH_SHORT).show();
            }
        });
    }
}