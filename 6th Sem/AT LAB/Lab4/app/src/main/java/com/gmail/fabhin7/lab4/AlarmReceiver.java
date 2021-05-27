package com.gmail.fabhin7.lab4;

import android.app.NotificationChannel;
import android.app.NotificationManager;
import android.app.PendingIntent;
import android.content.BroadcastReceiver;
import android.content.Context;
import android.content.Intent;
import android.os.Build;
import android.widget.Toast;

import androidx.core.app.NotificationCompat;
import androidx.core.app.NotificationManagerCompat;

public class AlarmReceiver extends BroadcastReceiver {
    private static final String channelName="alarm_channel";
    @Override
    public void onReceive(Context context, Intent intent) {
        Toast.makeText(context, "Inside Broadcast Receiver", Toast.LENGTH_SHORT).show();

        // 1. Create a notification manager
        // 2. Add a channel to the manager (only if the SDK version is > 26)
        // 3. Register a notification with the manager
        NotificationManager manager = (NotificationManager) context.getSystemService(Context.NOTIFICATION_SERVICE);
        if (Build.VERSION.SDK_INT >= Build.VERSION_CODES.O){
            NotificationChannel channel = new NotificationChannel(channelName, "Alarm channel", NotificationManager.IMPORTANCE_DEFAULT);
            manager.createNotificationChannel(channel);
        }

        NotificationCompat.Builder b = new NotificationCompat.Builder(context, channelName);
        b.setAutoCancel(true).setContentTitle("It is time").setContentText("Your alarm is ringing").setSmallIcon(android.R.drawable.star_on);
        manager.notify(100, b.build());
    }
}