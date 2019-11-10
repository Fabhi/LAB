import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

public class Comparison{
    public static void main(String args[]){
        container cont= new container();
    }
}

class container extends JFrame implements ActionListener{
    JButton b1,b2;
    JTextField t1,t2,t3;
    JLabel r;
    public container(){
        // TEXT FIELDS
        t1=new JTextField(10);
        t2=new JTextField(10);
        t3=new JTextField(10);
        add(t1);
        add(t2);
        add(t3);

        // BUTTONS
        b1= new JButton("Largest");
        b2= new JButton("Smallest");
        b1.setSize(10, 10);
        b2.setSize(10, 10);
        b1.addActionListener(this);
        b2.addActionListener(this);
        add(b1);
        add(b2);

        // LABEL
        r= new JLabel("Enter and Press");
        add(r);

        setLayout(new FlowLayout());
        setVisible(true);
        setSize(150,200);
        setDefaultCloseOperation(3);
        setLocationRelativeTo(null);
    }

    public void actionPerformed(ActionEvent ae){
        if(t1.getText().isEmpty() || t2.getText().isEmpty()|| t3.getText().isEmpty()){
            r.setText("One or more fields empty");
            return;}
        int a=Integer.parseInt(t1.getText().trim());
        int b=Integer.parseInt(t2.getText().trim());
        int c=Integer.parseInt(t3.getText().trim());
        int large=a>b?(a>c?a:c):(b>c?b:c);
        int small=a<b?(a<c?a:c):(b<c?b:c);
        if(ae.getActionCommand().equals("Largest"))
            r.setText(large+" is largest");
        else
            r.setText(small+" is smallest");
    }
}