import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

public class Palindrome{
    public static void main(String args[]){
        SwingUtilities.invokeLater(
            new Runnable(){
                public void run(){
                    new palin();
                }
            }
        );
    }
}

class palin extends JFrame implements ActionListener{
    JTextField tf;
    JButton but;
    JLabel lab;
    palin(){
        tf= new JTextField(10);
        but=new JButton("Check");
        lab= new JLabel("Enter a String");
        add(tf);
        add(but);
        add(lab);
        but.addActionListener(this);
        setLayout(new FlowLayout());
        setVisible(true);
        setDefaultCloseOperation(3);
        setSize(150,200);
        setLocationRelativeTo(null);
    }

    public void actionPerformed(ActionEvent ae){
        String s=tf.getText();
        boolean b=s.contentEquals(new StringBuffer(s).reverse());
        if(b)
            lab.setText("Palindrome");
        else
            lab.setText("Not a Palindrome");
    }
}
