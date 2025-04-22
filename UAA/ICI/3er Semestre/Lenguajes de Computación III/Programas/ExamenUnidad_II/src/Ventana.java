import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;
import java.util.logging.Level;
import java.util.logging.Logger;
import javax.swing.ImageIcon;
import javax.swing.JCheckBox;
import javax.swing.JComboBox;
import javax.swing.JOptionPane;

public class Ventana extends javax.swing.JFrame {
    String jdbcUrl = "jdbc:mariadb://localhost:3306";
    String username = "root";
    String password = "";
    String dBase = "Data";
    String table = "Poblacion";
    Connection conn;
    
    int cGen = 0;
    List<String> lisEst = new ArrayList<>();
    
    public Ventana() {
        initComponents();
        GenerarBase();
    }

    public void GenerarBase()
    {
        // Base de datos.
        try {
            conn = DriverManager.getConnection(jdbcUrl, username, password);
            Statement stmt = conn.createStatement();
            
            ResultSet resultSet = stmt.executeQuery("SHOW DATABASES LIKE '" + dBase + "';");

            // Se verifica la base de datos.
            if (resultSet.next()) {
                System.out.println(" >> La base de datos \"" + dBase + "\" ya existe.");
            } else {
                stmt.executeUpdate("CREATE DATABASE " + dBase + ";");
                System.out.println(" ++ La base de datos \"" + dBase + "\" ha sido creada.");
            }
            stmt.executeUpdate("USE " + dBase + ";");
            resultSet = stmt.executeQuery("SHOW TABLES LIKE '" + table + "';");

            // Se verifica la tabla en la base de datos.
            if (resultSet.next()) {
                System.out.println(" >> La tabla \"" + table + "\" ya existe.");
            } else {
                try {
                    stmt.executeUpdate("CREATE TABLE " + table + " (num1 int, num2 int, nombre varchar(50), edad int, genero varchar(1), estado varchar(3));");
                    System.out.println(" ++ La tabla \"" + table + "\" ha sido creada.");
                    try {
                        FileReader file = new FileReader("src/recursos/data.txt");
                        BufferedReader br = new BufferedReader(file);
                        String line;
                        
                        JOptionPane.showMessageDialog(this, "Se procederá a ingresar los datos.", "Base de Datos", JOptionPane.INFORMATION_MESSAGE);

                        line = br.readLine();
                        while (line != null) {
                            StringTokenizer t = new StringTokenizer(line, ",");
                            String num1 = t.nextToken();
                            String num2 = t.nextToken();
                            String nom = t.nextToken();
                            String edad = t.nextToken();
                            String gen = t.nextToken();
                            String est = t.nextToken();
                            stmt.executeUpdate("INSERT INTO " + table + " (num1, num2, nombre, edad, genero, estado) VALUES " + "(" + num1 + ", " + num2 + ", '" + nom + "', " + edad + ", '" + gen + "', '" + est + "');");
                            System.out.println(" >> Elemento agregado: " + "(" + num1 + ", " + num2 + ", '" + nom + "', " + edad + ", '" + gen + "', '" + est + "')");
                            line = br.readLine();
                        }
                        file.close();
                    } catch (IOException e) {
                        JOptionPane.showMessageDialog(this, "Ocurrió una excepción al leer el archivo.", "Base de Datos", JOptionPane.ERROR_MESSAGE);
                    }
                } catch (SQLException e) {
                    JOptionPane.showMessageDialog(this, "Ocurrió una excepción al ejecutar una consulta SQL.", "Base de Datos", JOptionPane.ERROR_MESSAGE);
                    Logger.getLogger(Ventana.class.getName()).log(Level.SEVERE, null, e);
                }
            }
        } catch (SQLException ex) {
            JOptionPane.showMessageDialog(this, "No se puedo acceder a la base de datos.", "Base de Datos", JOptionPane.ERROR_MESSAGE);
            Logger.getLogger(Ventana.class.getName()).log(Level.SEVERE, null, ex);
            System.exit(1);
        }
    }

    public void MostrarGrafica() {
        GraficaBarras gB = new GraficaBarras("Gráfica de Barras", dBase, table, cGen, lisEst);
        gB.setSize(850, 600);
        gB.setLocationRelativeTo(null);
        gB.show();
    }
   
    @SuppressWarnings("unchecked")
    // <editor-fold defaultstate="collapsed" desc="Generated Code">//GEN-BEGIN:initComponents
    private void initComponents() {

        fondo = new javax.swing.JPanel();
        btn = new javax.swing.JLabel();
        genero = new javax.swing.JComboBox<>();
        ags = new javax.swing.JCheckBox();
        dur = new javax.swing.JCheckBox();
        mty = new javax.swing.JCheckBox();
        oax = new javax.swing.JCheckBox();
        slp = new javax.swing.JCheckBox();
        zac = new javax.swing.JCheckBox();
        background = new javax.swing.JLabel();

        setDefaultCloseOperation(javax.swing.WindowConstants.EXIT_ON_CLOSE);
        setTitle("Consulta de Datos");
        setIconImage(new ImageIcon(getClass().getResource("/recursos/icono1.png")).getImage());
        setResizable(false);

        fondo.setBackground(new java.awt.Color(245, 249, 255));
        fondo.setLayout(null);

        btn.setHorizontalAlignment(javax.swing.SwingConstants.CENTER);
        btn.setIcon(new javax.swing.ImageIcon(getClass().getResource("/recursos/btn.png"))); // NOI18N
        btn.addMouseMotionListener(new java.awt.event.MouseMotionAdapter() {
            public void mouseMoved(java.awt.event.MouseEvent evt) {
                btnMouseMoved(evt);
            }
        });
        btn.addMouseListener(new java.awt.event.MouseAdapter() {
            public void mouseClicked(java.awt.event.MouseEvent evt) {
                btnMouseClicked(evt);
            }
            public void mouseExited(java.awt.event.MouseEvent evt) {
                btnMouseExited(evt);
            }
        });
        fondo.add(btn);
        btn.setBounds(150, 450, 200, 40);

        genero.setModel(new javax.swing.DefaultComboBoxModel<>(new String[] { "Hombres", "Mujeres", "Ambos (H y M)" }));
        genero.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                generoActionPerformed(evt);
            }
        });
        fondo.add(genero);
        genero.setBounds(80, 220, 340, 30);

        ags.setText("Aguascalientes");
        ags.setName("AGS"); // NOI18N
        ags.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                checkBoxActionPerformed(evt);
            }
        });
        fondo.add(ags);
        ags.setBounds(120, 320, 110, 20);

        dur.setText("Durango");
        dur.setName("DUR"); // NOI18N
        dur.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                checkBoxActionPerformed(evt);
            }
        });
        fondo.add(dur);
        dur.setBounds(120, 350, 110, 20);

        mty.setText("Monterrey");
        mty.setName("MTY"); // NOI18N
        mty.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                checkBoxActionPerformed(evt);
            }
        });
        fondo.add(mty);
        mty.setBounds(120, 380, 85, 20);

        oax.setText("Oaxaca");
        oax.setName("OAX"); // NOI18N
        oax.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                checkBoxActionPerformed(evt);
            }
        });
        fondo.add(oax);
        oax.setBounds(260, 320, 130, 20);

        slp.setText("San Luis Potosí");
        slp.setName("SLP"); // NOI18N
        slp.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                checkBoxActionPerformed(evt);
            }
        });
        fondo.add(slp);
        slp.setBounds(260, 350, 130, 20);

        zac.setText("Zacatecas");
        zac.setName("ZAC"); // NOI18N
        zac.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                checkBoxActionPerformed(evt);
            }
        });
        fondo.add(zac);
        zac.setBounds(260, 380, 130, 20);

        background.setIcon(new javax.swing.ImageIcon(getClass().getResource("/recursos/background.png"))); // NOI18N
        fondo.add(background);
        background.setBounds(0, 0, 500, 500);

        javax.swing.GroupLayout layout = new javax.swing.GroupLayout(getContentPane());
        getContentPane().setLayout(layout);
        layout.setHorizontalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addComponent(fondo, javax.swing.GroupLayout.DEFAULT_SIZE, 500, Short.MAX_VALUE)
        );
        layout.setVerticalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addComponent(fondo, javax.swing.GroupLayout.DEFAULT_SIZE, 500, Short.MAX_VALUE)
        );

        pack();
        setLocationRelativeTo(null);
    }// </editor-fold>//GEN-END:initComponents

    private void btnMouseMoved(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_btnMouseMoved
        btn.setIcon(new ImageIcon(getClass().getResource("/recursos/btnPressed.png")));
    }//GEN-LAST:event_btnMouseMoved

    private void btnMouseExited(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_btnMouseExited
        btn.setIcon(new ImageIcon(getClass().getResource("/recursos/btn.png")));
    }//GEN-LAST:event_btnMouseExited

    private void btnMouseClicked(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_btnMouseClicked
        if(lisEst.size() > 0)
            MostrarGrafica();
        else
            JOptionPane.showMessageDialog(this, "Selecciona al menos una ciudad.", "Vizualizar", JOptionPane.ERROR_MESSAGE);
    }//GEN-LAST:event_btnMouseClicked

    private void checkBoxActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_checkBoxActionPerformed
        JCheckBox cB = (JCheckBox) evt.getSource();
        
        if(cB.isSelected())
            lisEst.add(cB.getName());
        else
            lisEst.remove(cB.getName());
    }//GEN-LAST:event_checkBoxActionPerformed

    private void generoActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_generoActionPerformed
        JComboBox cB = (JComboBox) evt.getSource();
        cGen = cB.getSelectedIndex();
    }//GEN-LAST:event_generoActionPerformed

    public static void main(String args[]) {
        try {
            for (javax.swing.UIManager.LookAndFeelInfo info : javax.swing.UIManager.getInstalledLookAndFeels()) {
                if ("Nimbus".equals(info.getName())) {
                    javax.swing.UIManager.setLookAndFeel(info.getClassName());
                    break;
                }
            }
        } catch (ClassNotFoundException ex) {
            java.util.logging.Logger.getLogger(Ventana.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (InstantiationException ex) {
            java.util.logging.Logger.getLogger(Ventana.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (IllegalAccessException ex) {
            java.util.logging.Logger.getLogger(Ventana.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (javax.swing.UnsupportedLookAndFeelException ex) {
            java.util.logging.Logger.getLogger(Ventana.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        }
        //</editor-fold>

        java.awt.EventQueue.invokeLater(new Runnable() {
            public void run() {
                new Ventana().setVisible(true);
            }
        });
    }

    // Variables declaration - do not modify//GEN-BEGIN:variables
    private javax.swing.JCheckBox ags;
    private javax.swing.JLabel background;
    private javax.swing.JLabel btn;
    private javax.swing.JCheckBox dur;
    private javax.swing.JPanel fondo;
    private javax.swing.JComboBox<String> genero;
    private javax.swing.JCheckBox mty;
    private javax.swing.JCheckBox oax;
    private javax.swing.JCheckBox slp;
    private javax.swing.JCheckBox zac;
    // End of variables declaration//GEN-END:variables
}
