import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

public class First{
    public static void main(String args[]){
        Container cont= new Container();
    }
}

class Container extends JFrame{
    public Container(){
        JTextField t1= new JTextField(20);
        JTextField t2= new JTextField(20);
        JButton b= new JButton("OK");
        JLabel l= new JLabel("RESULT");
        add(t1);
        add(t2);
        add(b);
        add(l);

        b.addActionListener(new ActionListener());
        
        setLayout(new FlowLayout());
        setVisible(true);
        setSize(400,400);
        setDefaultCloseOperation(3);
    }
    public void actionPerformed(java.awt.event.ActionEvent ae){

    }
}