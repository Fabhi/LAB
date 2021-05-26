package com.gmail.fabhin7.lab4;

import androidx.appcompat.app.AppCompatActivity;
import androidx.core.app.NotificationCompat;

import android.app.AlarmManager;
import android.app.NotificationChannel;
import android.app.NotificationManager;
import android.app.PendingIntent;
import android.content.Intent;
import android.os.Build;
import android.os.Bundle;
import android.widget.Button;
import android.widget.TimePicker;

import java.util.Calendar;

public class A1Activity extends AppCompatActivity {
    String CHANNEL_ID = "234";

    NotificationManager notificationManager;

    private void createNotificationChannel() {
        if (Build.VERSION.SDK_INT >= Build.VERSION_CODES.O) {
            CharSequence name = "Channel1";
            String description = "Channel1";

            int importance = NotificationManager.IMPORTANCE_DEFAULT;
            NotificationChannel channel = new NotificationChannel(CHANNEL_ID, name, importance);
            channel.setDescription(description);

            notificationManager = getSystemService(NotificationManager.class);
            notificationManager.createNotificationChannel(channel);
        }
    }

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_a1);

        createNotificationChannel();

        Intent intent = new Intent(this, A1Activity.class);
        PendingIntent pIntent = PendingIntent.getActivity(this, 0, intent, 0);
        TimePicker timePicker = findViewById(R.id.timepicker);
        AlarmManager alarmManager = (AlarmManager) getSystemService(ALARM_SERVICE);
        Button button = findViewById(R.id.button);

        NotificationCompat.Builder builder = new NotificationCompat.Builder(this, CHANNEL_ID)
                .setSmallIcon(R.drawable.ic_launcher_foreground)
                .setContentTitle("Alarm!")
                .setContentText("Time's up!")
                .setAutoCancel(true);

        button.setOnClickListener(v -> {
//             notificationManager.notify(0, n);

            long timePeriod;
            if(Build.VERSION.SDK_INT >= 23) {
                Calendar calendar = Calendar.getInstance();
                calendar.set(Calendar.HOUR_OF_DAY, timePicker.getHour());
                calendar.set(Calendar.MINUTE, timePicker.getMinute());
                calendar.set(Calendar.SECOND, 0);
                calendar.set(Calendar.MILLISECOND, 0);
                timePeriod = calendar.getTimeInMillis();
                AlarmManager.AlarmClockInfo aci = new AlarmManager.AlarmClockInfo(timePeriod, pIntent);
                Intent intent2 = new Intent();
                intent2.setAction("alarm_went_off");
                PendingIntent pd = PendingIntent.getBroadcast(A1Activity.this, 0, intent2, 0);
                alarmManager.setAlarmClock(aci,pd);
            }
        });
    }
}