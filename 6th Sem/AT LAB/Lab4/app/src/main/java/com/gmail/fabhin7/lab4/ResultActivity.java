package com.gmail.fabhin7.lab4;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.widget.TextView;

public class ResultActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_result);
        int score = getIntent().getIntExtra("Score", 0);

        ((TextView) findViewById(R.id.score_view)).setText(score+" out of 10");
    }
}