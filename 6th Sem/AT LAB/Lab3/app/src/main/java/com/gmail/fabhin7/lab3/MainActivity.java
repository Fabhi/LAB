package com.gmail.fabhin7.lab3;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.Toast;

import java.util.Random;

public class MainActivity extends AppCompatActivity {
    static int upperbound = 11;
    int number;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        Random rand = new Random();
        number = rand.nextInt(upperbound);

        EditText numberInput = findViewById(R.id.number_input);
        Button checkButton = findViewById(R.id.check_button);

        checkButton.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                int numb = Integer.parseInt(String.valueOf(numberInput.getText()));

                if(numb < number)
                    Toast.makeText(getApplicationContext(), "Too Low", Toast.LENGTH_SHORT).show();
                else if(numb > number)
                    Toast.makeText(getApplicationContext(), "Too High", Toast.LENGTH_SHORT).show();
                else{
                    Toast.makeText(getApplicationContext(), "You guessed the number", Toast.LENGTH_SHORT).show();
                    number = rand.nextInt(upperbound);
                    Toast.makeText(getApplicationContext(), "GAME RESET", Toast.LENGTH_SHORT).show();
                }
            }
        });
    }
}