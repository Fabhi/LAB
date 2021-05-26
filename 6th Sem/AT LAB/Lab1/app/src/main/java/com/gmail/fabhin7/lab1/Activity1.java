package com.gmail.fabhin7.lab1;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.os.Bundle;
import android.text.TextUtils;
import android.util.Patterns;
import android.view.View;
import android.view.ViewGroup;
import android.widget.Button;
import android.widget.EditText;
import android.widget.Toast;

import java.util.regex.Pattern;

public class Activity1 extends AppCompatActivity {

    private EditText nameEdit, emailEdit, numberEdit, passwordEdit;
    Button validateButton, nextPageButton;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_1);
        nameEdit = findViewById(R.id.name_edit);
        emailEdit = findViewById(R.id.email_edit);
        numberEdit = findViewById(R.id.number_edit);
        passwordEdit = findViewById(R.id.password_edit);
        validateButton = findViewById(R.id.validate_button);
        nextPageButton = findViewById(R.id.next_page_button);
        validateButton.setOnClickListener(view -> {

            boolean validEmail = isValidEmail(emailEdit.getText());
            boolean validNumber = isValidMobile(numberEdit.getText());
            boolean validName = !TextUtils.isEmpty(nameEdit.getText());
            boolean validPassword = !TextUtils.isEmpty(passwordEdit.getText());
            boolean allValid = validEmail && validNumber && validName && validPassword;

            if (validEmail){
                emailEdit.setBackgroundResource(R.drawable.edtnormal);
            } else {
                emailEdit.setError("Invalid Email");
                emailEdit.setBackgroundResource(R.drawable.edterr);
            }

            if (validNumber){
                numberEdit.setBackgroundResource(R.drawable.edtnormal);
            } else {
                numberEdit.setError("Mobile Number should be 7-13 digits");
                numberEdit.setBackgroundResource(R.drawable.edterr);
            }

            if (validName) {
                nameEdit.setBackgroundResource(R.drawable.edtnormal);
            } else {
                nameEdit.setBackgroundResource(R.drawable.edterr);
            }

            if (validPassword){
                passwordEdit.setBackgroundResource(R.drawable.edtnormal);
            } else {
                passwordEdit.setBackgroundResource(R.drawable.edterr);
            }

            if(allValid) {
                Toast.makeText(getApplicationContext(), "Welcome " + nameEdit.getText(), Toast.LENGTH_SHORT).show();
            } else {
                Toast.makeText(getApplicationContext(), "Invalid Entries found", Toast.LENGTH_SHORT).show();
            }
        });

        nextPageButton.setOnClickListener(v -> startActivity(new Intent(Activity1.this, ActivityAdditional.class)));
    }

    public static boolean isValidEmail(CharSequence target) {
        return (!TextUtils.isEmpty(target) && Patterns.EMAIL_ADDRESS.matcher(target).matches());
    }

    public static boolean isValidMobile(CharSequence target) {
        if(!Pattern.matches("[a-zA-Z]+", target)) {
            return target.length() > 6 && target.length() <= 13;
        }
        return false;
    }
    public void printer(View myView){
        Toast.makeText(getApplicationContext(),"You pressed the button", Toast.LENGTH_SHORT).show();
    }
}