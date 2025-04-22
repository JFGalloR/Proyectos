package ejercicio_interfaz_02;

import java.awt.BorderLayout;
import java.awt.FlowLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.StringTokenizer;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.JTextField;
import java.awt.Color;

public class Ejercicio_Interfaz_02 extends JPanel implements ActionListener {

    JButton b1, b2;
    JTextField t1, t2, t3, t4, t5, t6;

    public Ejercicio_Interfaz_02() {
        t1 = new JTextField(30);
        t2 = new JTextField(30);
        t3 = new JTextField(30);
        t4 = new JTextField(30);
        t5 = new JTextField(30);
        t6 = new JTextField(30);

        b1 = new JButton("            Colocar Mayus             ");
        b2 = new JButton("     Verificar palabra palindroma     ");

        t5.addActionListener(this);
        b1.addActionListener(this);
        b2.addActionListener(this);

        setLayout(new FlowLayout());
        add(t1);
        add(t2);
        add(b1);
        add(t3);
        add(t4);
        add(b2);
        add(t5);
        add(t6);
    }   //aqui termina constructor

    public void actionPerformed(ActionEvent ae) {
        if (ae.getSource() == b1) {
            String nombre;
            StringBuilder nuevo = new StringBuilder();
            StringTokenizer st = new StringTokenizer(t1.getText());
            while (st.hasMoreElements()) {
                nombre = st.nextToken();
                nuevo.append(nombre.toUpperCase().charAt(0) + nombre.substring(1) + " ");
            }
            t2.setText(nuevo.toString());
        }

        if (ae.getSource() == b2) {
            String palabra1 = new String(t3.getText().toString());
            StringBuilder palabra2 = new StringBuilder(palabra1);
            if (palabra1.equals(palabra2.reverse().toString())) {
                t4.setText("Si es palindroma");
            } else {
                t4.setText("No es palindroma");
            }
        }

        if (ae.getSource() == t5) {
            int numMayor = -99999;
            StringTokenizer st = new StringTokenizer(t5.getText().toString(), ",");
            while (st.hasMoreElements()) {
                Integer n = new Integer(st.nextToken());
                numMayor = (n>numMayor)?n:numMayor;
            }
            t6.setText("El numero mayor es " + numMayor);
        }
    }

    public static void main(String[] args) {
        
        JFrame.setDefaultLookAndFeelDecorated(false);
        JFrame frame = new JFrame("Ejercicio Interfaz");
        
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setBounds(200, 200, 500, 300);
        
        Ejercicio_Interfaz_02 ventana = new Ejercicio_Interfaz_02();
        
        ventana.setBackground(new Color(197, 203, 231));
        frame.getContentPane().add(ventana, BorderLayout.CENTER);
        
        frame.setVisible(true);
    }
}
