package com.gmail.fabhin7.lab4;

import androidx.appcompat.app.AlertDialog;
import androidx.appcompat.app.AppCompatActivity;
import android.content.Intent;
import android.os.AsyncTask;
import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.widget.Button;
import android.widget.TextView;

import org.json.JSONArray;
import org.json.JSONException;
import org.json.JSONObject;

import java.io.BufferedInputStream;
import java.io.BufferedReader;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.UnsupportedEncodingException;
import java.net.HttpURLConnection;
import java.net.URL;
import java.net.URLDecoder;

public class Q1Activity extends AppCompatActivity {
    Question[] questions = new Question[10];
    Button startButton, button1, button2, button3, button4;
    TextView questionView;
    int score, current = 0;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_q1);
        getData gD = new getData();
        gD.execute();
        startButton = findViewById(R.id.start_button);
        startButton.setOnClickListener(v -> startQuiz());
    }

    protected void startQuiz(){
        setContentView(R.layout.quiz_layout);
        questionView = findViewById(R.id.question);
        button1 = findViewById(R.id.button_1);
        button2 = findViewById(R.id.button_2);
        button3 = findViewById(R.id.button_3);
        button4 = findViewById(R.id.button_4);
        button1.setOnClickListener(this::handler);
        button2.setOnClickListener(this::handler);
        button3.setOnClickListener(this::handler);
        button4.setOnClickListener(this::handler);
        updatePage(questions[current]);
    }

    protected void handler(View v) {
        String selected = ((Button) v).getText().toString();
        Log.i("selected", selected);
        Log.i("correct", questions[current].getAnswer());
        if(questions[current].isCorrect(selected)) score++;
        if(current == 9){
            showPopup();
            return;
        }
        current += 1;
        updatePage(questions[current]);
    }

    protected void showPopup() {
        Log.i("Score", String.valueOf(score));
        setContentView(R.layout.quiz_over);
        new AlertDialog.Builder(this)
                .setTitle("Submit Quiz")
                .setMessage("Are you sure you want to submit this quiz?")
                .setPositiveButton(android.R.string.yes, (dialog, which) -> {
                    Intent intent = new Intent(this, ResultActivity.class);
                    intent.putExtra("Score", score);
                    startActivity(intent);
                })
                .setNegativeButton(android.R.string.no, null)
                .setIcon(android.R.drawable.checkbox_on_background)
                .show();
    }

    protected void updatePage(Question q) {
        questionView.setText(q.question);
        button1.setText(q.answers[0]);
        button2.setText(q.answers[1]);
        button3.setText(q.answers[2]);
        button4.setText(q.answers[3]);
    }

    public class getData extends AsyncTask<String, String, String> {
        HttpURLConnection urlConnection;
        String endpoint = "https://opentdb.com/api.php?amount=10&category=18&difficulty=easy&type=multiple&encode=url3986";

        @Override
        protected String doInBackground(String... URL) {
            StringBuilder result = new StringBuilder();
            try {
                java.net.URL url = new URL(endpoint);
                urlConnection = (HttpURLConnection) url.openConnection();
                InputStream in = new BufferedInputStream(urlConnection.getInputStream());
                BufferedReader reader = new BufferedReader(new InputStreamReader(in));
                String line;
                while ((line = reader.readLine()) != null) {
                    result.append(line);
                }
            }catch( Exception e) {
                e.printStackTrace();
            }
            finally {
                urlConnection.disconnect();
            }
            return result.toString();
        }

        @Override
        protected void onPostExecute(String result) {
            JSONObject reader;
            try {
                reader =  new JSONObject(result);
                JSONArray array = reader.getJSONArray("results");
                for (int i=0;i<array.length(); i++){
                    JSONObject object = array.getJSONObject(i);
                    String question = URLDecoder.decode(object.getString("question"), "UTF-8");
                    String correct = URLDecoder.decode(object.getString("correct_answer"),"UTF-8");
                    JSONArray incorrect = object.getJSONArray("incorrect_answers");
                    String incorrect1 = URLDecoder.decode(incorrect.getString(0), "UTF-8") ;
                    String incorrect2 = URLDecoder.decode(incorrect.getString(1), "UTF-8") ;
                    String incorrect3 = URLDecoder.decode(incorrect.getString(2), "UTF-8") ;
                    questions[i] = new Question(question, correct, incorrect1, incorrect2, incorrect3, correct);
                    Log.i("Question",question);
                    Log.i("Correct Answer", correct);
                    Log.i("Incorrect", incorrect.toString());
                }
            } catch (JSONException | UnsupportedEncodingException e) {
                e.printStackTrace();
            }
            startButton.setEnabled(true);
        }
    }

}