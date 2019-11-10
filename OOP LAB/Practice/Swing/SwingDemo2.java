import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

class SwingDemo2 {

    int i1, i2, i3;
    String password;
    JLabel jlab;
    JTextField jf1;
    JTextField jf2;
    JTextField jf3;
    JButton jb1;
    JButton jb2;
    JPanel jp;

    SwingDemo2() {
        JFrame jfrm = new JFrame("A Simple Swing Application");
        jfrm.setVisible(true);
        jfrm.setSize(400, 400);
        jfrm.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        GridLayout layout1 = new GridLayout(3, 1);
        jfrm.setLayout(layout1);
        layout1.setHgap(10);
        layout1.setVgap(10);

        jp = new JPanel();
        jfrm.add(jp);
        jp.setBackground(Color.pink);

        FlowLayout layout = new FlowLayout();
        layout.setHgap(10);
        layout.setVgap(10);
        jp.setLayout(layout);

        jlab = new JLabel(" Enter numbers and press button to get the Results ");
        jfrm.add(jlab);

        jf1 = new JTextField(10);
        jf2 = new JTextField(10);
        jf3 = new JTextField(10);
        jp.add(jf1);
        jp.add(jf2);
        jp.add(jf3);

        jb1 = new JButton("Largest");
        jb2 = new JButton("Smallest");
        jb1.setBackground(Color.red);
        jb2.setBackground(Color.red);
        jfrm.add(jb1);
        jfrm.add(jb2);

        jb1.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                String content = jf1.getText();
                System.out.println("password" + content);
                i1 = Integer.parseInt(content);

                content = jf2.getText();
                System.out.println("password" + content);
                i2 = Integer.parseInt(content);
                
                content = jf3.getText();
                System.out.println("password" + content);
                i3 = Integer.parseInt(content);

                if ((i1 > i2) && (i1 > i3)) {
                    jf1.setText(Integer.toString(i1));
                    jlab.setText(Integer.toString(i1) + "is the largest");
                }
                else if ((i2 > i1) && (i2 > i3)) {
                    jf2.setText(Integer.toString(i2));
                    jlab.setText(Integer.toString(i2) + "is the largest");
                }
                else if ((i3 > i1) && (i3 > i2)) {
                    jf3.setText(Integer.toString(i3));
                    jlab.setText(Integer.toString(i3) + "is the largest");
                }
            }
        });

        jb2.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                String content = jf1.getText();
                System.out.println("password" + content);
                i1 = Integer.parseInt(content);
                content = jf2.getText();
                System.out.println("password" + content);
                i2 = Integer.parseInt(content);
                content = jf3.getText();
                System.out.println("password" + content);
                i3 = Integer.parseInt(content);

                if ((i1 < i2) && (i1 < i3)) {

                    jf1.setText(Integer.toString(i1));
                    jlab.setText(Integer.toString(i1) + "is the smallest");
                } else if ((i2 < i1) && (i2 < i3)) {

                    jf2.setText(Integer.toString(i2));
                    jlab.setText(Integer.toString(i2) + "is the smallest");
                }

                else if ((i3 < i1) && (i3 < i2)) {

                    jf3.setText(Integer.toString(i3));
                    jlab.setText(Integer.toString(i3) + "is the smallest");
                }
            }

        });

    }

    public static void main(String args[]) {
        SwingUtilities.invokeLater(new Runnable() {
            public void run() {
                new SwingDemo2();
            }
        });

    }

}