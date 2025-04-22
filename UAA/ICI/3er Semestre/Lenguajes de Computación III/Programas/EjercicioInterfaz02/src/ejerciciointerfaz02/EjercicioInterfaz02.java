
package EjercicioInterfaz02;

import java.awt.BorderLayout;
import java.awt.FlowLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.StringTokenizer;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.JTextField;

public class EjercicioInterfaz02 extends JPanel implements ActionListener {

    JButton b1, b2;
    JTextField t1, t2, t3, t4, t5, t6;

    public EjercicioInterfaz02()
    {
        t1 = new JTextField(25);
        t2 = new JTextField(15);
        t3 = new JTextField(25);
        t4 = new JTextField(25);
        t5 = new JTextField(25);
        t6 = new JTextField(25);

        b1 = new JButton("Poner mayus");
        b2 = new JButton("Verificar palabra palídroma");

        t5.addActionListener(this);
        b1.addActionListener(this);
        b2.addActionListener(this);

        setLayout(new FlowLayout());
        add(t1);
        add(b1);
        add(t2);
        add(t3);
        add(b2);
        add(t4);
        add(t5);
        add(t6);
    }

    public void actionPerformed(ActionEvent ae) {
        if (ae.getSource() == b1) {
            String a2;
            StringBuilder a3 = new StringBuilder();
            StringTokenizer st = new StringTokenizer(t1.getText());
            while (st.hasMoreElements()) {

                a2 = st.nextToken();
                a3.append(a2.toUpperCase().charAt(0) + a2.substring(1) + " ");

            }
            t2.setText(a3.toString());
        }

        if (ae.getSource() == b2) {

            String a2 = new String(t3.getText().toString());
            StringBuilder a3 = new StringBuilder(a2);

            if (a2.equals(a3.reverse().toString())) {
                t4.setText("es palindromo ");
            } else {
                t4.setText("no es palindromo ");
            }
        }

        if (ae.getSource() == t5) {

            int mayor = -99;
            StringTokenizer st = new StringTokenizer(t5.getText().toString(), ",");
            while (st.hasMoreElements()) {

                Integer n = new Integer(st.nextToken());

                if (n > mayor)
                    mayor = n;

            }
            t6.setText("el mayor es " + mayor);
        }

    }

    public static void main(String[] args) {
        JFrame.setDefaultLookAndFeelDecorated(true);
        JFrame frame = new JFrame("Ejercicio Interfaz");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        EjercicioInterfaz02 bot = new EjercicioInterfaz02();
        frame.getContentPane().add(bot, BorderLayout.CENTER);

        frame.setBounds(100, 100, 400, 432);
        frame.setVisible(true);
    }
}