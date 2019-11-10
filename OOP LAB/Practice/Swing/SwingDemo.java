import javax.swing.*;

class SwingDemo{
    SwingDemo(){
        JFrame jfrm= new JFrame("First Swingers!");
        jfrm.setSize(500,100);
        jfrm.setDefaultCloseOperation(3);
        JLabel jlb= new JLabel("Swinging here!");
        jfrm.add(jlb);
        jfrm.setVisible(true);
        jfrm.setLocation(1024/2,768/2);
    }
    public static void main(String args[]){
        SwingUtilities.invokeLater(
            new Runnable(){
                public void run(){
                    new SwingDemo();
                }
        });
    }
}