
import java.awt.Color;
import javax.swing.ImageIcon;
import java.sql.*;
import java.util.logging.Level;
import java.util.logging.Logger;
import javax.swing.JOptionPane;
import javax.swing.table.DefaultTableModel;

public class Ventana extends javax.swing.JFrame {

    String jdbcUrl = "jdbc:mariadb://localhost:3306";
    String username = "root";
    String password = "";
    String dBase = "registros";
    String table = "alumnos";
    Connection conn;
    DefaultTableModel model;

    int idA;
    String nombreA;
    int edadA;
    
    public Ventana() {
        initComponents();
        verificarBase();
        model = new DefaultTableModel(
            new Object [][] {},
            new String [] {
                "ID", "Nombre", "Edad"
            }
        );
        tabla.setModel(model);
    }

    private void verificarBase() {
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
                    stmt.executeUpdate("CREATE TABLE " + table + " (id int, nombre varchar(50), edad int);");
                    System.out.println(" ++ La tabla \"" + table + "\" ha sido creada.");
                } catch (SQLException e) {
                    Logger.getLogger(Ventana.class.getName()).log(Level.SEVERE, null, e);
                }
            }
        } catch (SQLException ex) {
            JOptionPane.showMessageDialog(this, "Ocurrio una excepción.", "Base de Datos", JOptionPane.ERROR_MESSAGE);
            Logger.getLogger(Ventana.class.getName()).log(Level.SEVERE, null, ex);
        }
    }

    @SuppressWarnings("unchecked")
    // <editor-fold defaultstate="collapsed" desc="Generated Code">//GEN-BEGIN:initComponents
    private void initComponents() {

        jPanel1 = new javax.swing.JPanel();
        jPanel2 = new javax.swing.JPanel();
        jLabel2 = new javax.swing.JLabel();
        jLabel1 = new javax.swing.JLabel();
        jPanel4 = new javax.swing.JPanel();
        jPanel6 = new javax.swing.JPanel();
        name = new javax.swing.JTextField();
        age = new javax.swing.JSpinner();
        jPanel5 = new javax.swing.JPanel();
        jPanel9 = new javax.swing.JPanel();
        jPanel7 = new javax.swing.JPanel();
        jLabel3 = new javax.swing.JLabel();
        id = new javax.swing.JTextField();
        jLabel4 = new javax.swing.JLabel();
        jLabel5 = new javax.swing.JLabel();
        registrar = new javax.swing.JButton();
        borrar = new javax.swing.JButton();
        buscar = new javax.swing.JButton();
        jScrollPane1 = new javax.swing.JScrollPane();
        tabla = new javax.swing.JTable();
        ver = new javax.swing.JButton();
        label = new javax.swing.JLabel();

        setDefaultCloseOperation(javax.swing.WindowConstants.EXIT_ON_CLOSE);
        setTitle("Base de Datos");
        setIconImage(new ImageIcon(getClass().getResource("icono.png")).getImage());
        setMaximumSize(new java.awt.Dimension(370, 540));
        setPreferredSize(new java.awt.Dimension(370, 540));
        setResizable(false);
        setSize(new java.awt.Dimension(370, 540));

        jPanel1.setBackground(new java.awt.Color(255, 255, 255));
        jPanel1.setLayout(null);

        jPanel2.setBackground(new java.awt.Color(0, 0, 0));
        jPanel2.setLayout(null);

        jLabel2.setIcon(new javax.swing.ImageIcon(getClass().getResource("/image.png"))); // NOI18N
        jLabel2.setToolTipText("");
        jPanel2.add(jLabel2);
        jLabel2.setBounds(40, 0, 70, 88);

        jLabel1.setBackground(new java.awt.Color(0, 0, 0));
        jLabel1.setFont(new java.awt.Font("Segoe UI Black", 1, 24)); // NOI18N
        jLabel1.setForeground(new java.awt.Color(255, 255, 255));
        jLabel1.setHorizontalAlignment(javax.swing.SwingConstants.CENTER);
        jLabel1.setText("BASE DE DATOS");
        jPanel2.add(jLabel1);
        jLabel1.setBounds(120, 20, 198, 50);

        jPanel1.add(jPanel2);
        jPanel2.setBounds(0, 0, 370, 90);

        jPanel4.setBackground(new java.awt.Color(153, 153, 153));

        javax.swing.GroupLayout jPanel4Layout = new javax.swing.GroupLayout(jPanel4);
        jPanel4.setLayout(jPanel4Layout);
        jPanel4Layout.setHorizontalGroup(
            jPanel4Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGap(0, 330, Short.MAX_VALUE)
        );
        jPanel4Layout.setVerticalGroup(
            jPanel4Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGap(0, 10, Short.MAX_VALUE)
        );

        jPanel1.add(jPanel4);
        jPanel4.setBounds(20, 100, 330, 10);

        jPanel6.setBackground(new java.awt.Color(204, 204, 204));

        javax.swing.GroupLayout jPanel6Layout = new javax.swing.GroupLayout(jPanel6);
        jPanel6.setLayout(jPanel6Layout);
        jPanel6Layout.setHorizontalGroup(
            jPanel6Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGap(0, 330, Short.MAX_VALUE)
        );
        jPanel6Layout.setVerticalGroup(
            jPanel6Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGap(0, 10, Short.MAX_VALUE)
        );

        jPanel1.add(jPanel6);
        jPanel6.setBounds(20, 110, 330, 10);
        jPanel1.add(name);
        name.setBounds(110, 160, 160, 20);

        age.addChangeListener(new javax.swing.event.ChangeListener() {
            public void stateChanged(javax.swing.event.ChangeEvent evt) {
                ageStateChanged(evt);
            }
        });
        jPanel1.add(age);
        age.setBounds(280, 160, 60, 20);

        jPanel5.setBackground(new java.awt.Color(0, 0, 0));
        jPanel5.setLayout(null);
        jPanel1.add(jPanel5);
        jPanel5.setBounds(0, 90, 20, 450);

        jPanel9.setBackground(new java.awt.Color(0, 0, 0));
        jPanel9.setLayout(null);
        jPanel1.add(jPanel9);
        jPanel9.setBounds(350, 90, 20, 450);

        jPanel7.setBackground(new java.awt.Color(102, 102, 102));

        javax.swing.GroupLayout jPanel7Layout = new javax.swing.GroupLayout(jPanel7);
        jPanel7.setLayout(jPanel7Layout);
        jPanel7Layout.setHorizontalGroup(
            jPanel7Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGap(0, 330, Short.MAX_VALUE)
        );
        jPanel7Layout.setVerticalGroup(
            jPanel7Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGap(0, 10, Short.MAX_VALUE)
        );

        jPanel1.add(jPanel7);
        jPanel7.setBounds(20, 90, 330, 10);

        jLabel3.setFont(new java.awt.Font("Segoe UI", 1, 14)); // NOI18N
        jLabel3.setText("Edad");
        jPanel1.add(jLabel3);
        jLabel3.setBounds(280, 140, 50, 20);
        jPanel1.add(id);
        id.setBounds(30, 160, 70, 20);

        jLabel4.setFont(new java.awt.Font("Segoe UI", 1, 14)); // NOI18N
        jLabel4.setText("ID");
        jPanel1.add(jLabel4);
        jLabel4.setBounds(30, 140, 37, 20);

        jLabel5.setFont(new java.awt.Font("Segoe UI", 1, 14)); // NOI18N
        jLabel5.setText("Nombre");
        jPanel1.add(jLabel5);
        jLabel5.setBounds(110, 140, 60, 17);

        registrar.setBackground(new java.awt.Color(232, 232, 232));
        registrar.setText("Registrar");
        registrar.setBorder(javax.swing.BorderFactory.createLineBorder(new java.awt.Color(0, 0, 0)));
        registrar.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                registrarActionPerformed(evt);
            }
        });
        jPanel1.add(registrar);
        registrar.setBounds(140, 200, 90, 20);

        borrar.setBackground(new java.awt.Color(232, 232, 232));
        borrar.setText("Borrar");
        borrar.setBorder(javax.swing.BorderFactory.createLineBorder(new java.awt.Color(0, 0, 0)));
        borrar.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                borrarActionPerformed(evt);
            }
        });
        jPanel1.add(borrar);
        borrar.setBounds(140, 230, 90, 20);

        buscar.setBackground(new java.awt.Color(253, 253, 253));
        buscar.setText("Buscar");
        buscar.setBorder(javax.swing.BorderFactory.createLineBorder(new java.awt.Color(0, 0, 0)));
        buscar.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                buscarActionPerformed(evt);
            }
        });
        jPanel1.add(buscar);
        buscar.setBounds(140, 260, 90, 20);

        tabla.setFont(new java.awt.Font("Segoe UI", 0, 14)); // NOI18N
        tabla.setModel(new javax.swing.table.DefaultTableModel(
            new Object [][] {
                {null, null, null},
                {null, null, null},
                {null, null, null},
                {null, null, null}
            },
            new String [] {
                "ID", "Nombre", "Edad"
            }
        ) {
            boolean[] canEdit = new boolean [] {
                false, false, false
            };

            public boolean isCellEditable(int rowIndex, int columnIndex) {
                return canEdit [columnIndex];
            }
        });
        tabla.setEnabled(false);
        tabla.setRowHeight(22);
        jScrollPane1.setViewportView(tabla);

        jPanel1.add(jScrollPane1);
        jScrollPane1.setBounds(30, 310, 310, 160);

        ver.setBackground(new java.awt.Color(0, 0, 0));
        ver.setFont(new java.awt.Font("Segoe UI", 0, 10)); // NOI18N
        ver.setForeground(new java.awt.Color(255, 255, 255));
        ver.setText("Ver todo");
        ver.setBorder(javax.swing.BorderFactory.createLineBorder(new java.awt.Color(0, 0, 0)));
        ver.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                verActionPerformed(evt);
            }
        });
        jPanel1.add(ver);
        ver.setBounds(280, 480, 60, 20);

        label.setText("texto:");
        jPanel1.add(label);
        label.setBounds(37, 290, 300, 16);

        javax.swing.GroupLayout layout = new javax.swing.GroupLayout(getContentPane());
        getContentPane().setLayout(layout);
        layout.setHorizontalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addComponent(jPanel1, javax.swing.GroupLayout.DEFAULT_SIZE, 370, Short.MAX_VALUE)
        );
        layout.setVerticalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addComponent(jPanel1, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
        );

        setSize(new java.awt.Dimension(386, 548));
        setLocationRelativeTo(null);
    }// </editor-fold>//GEN-END:initComponents

    private boolean validar() {                                            
        if(id.getText().isBlank() || !id.getText().matches("^[0-9]+$"))
        {
            return false;
        }
        if(name.getText().isBlank())
        {
            return false;
        }
        idA = Integer.parseInt(id.getText());
        nombreA = name.getText();
        edadA = (int)age.getValue();
        return true;
    }    
    
    private void registrarActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_registrarActionPerformed
        if(validar())
        {
            Statement stmt;
            model.setRowCount(0);
            label.setText("");
            try {
                stmt = conn.createStatement();
                stmt.executeUpdate("INSERT INTO alumnos (id, nombre, edad) VALUES (" + idA + ", '" + nombreA + "'," + edadA + ");");
                label.setForeground(new Color(0,102,0));label.setText("Se muestra alumno agregado:");
                model.addRow(new Object[]{idA, nombreA, edadA});
                JOptionPane.showMessageDialog(this, "Alumno registrado correctamente.", "Registro Alumno", JOptionPane.INFORMATION_MESSAGE);
                System.out.println(" ++ Alumno registrado correctamente.");
            } catch (SQLException ex) {
                JOptionPane.showMessageDialog(this, "Ocurrio una excepción.", "Base de Datos", JOptionPane.ERROR_MESSAGE);
                Logger.getLogger(Ventana.class.getName()).log(Level.SEVERE, null, ex);
            }
        }
        else
        {
            JOptionPane.showMessageDialog(this, "Llena correctamente los campos.", "Base de Datos", JOptionPane.WARNING_MESSAGE);
        }
    }//GEN-LAST:event_registrarActionPerformed

    private void borrarActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_borrarActionPerformed
        if(validar())
        {
            Statement stmt;
            model.setRowCount(0);
            label.setText("");
            try {
                stmt = conn.createStatement();
                
                ResultSet rs = stmt.executeQuery("SELECT * FROM alumnos WHERE id=" + idA + " AND nombre='" + nombreA + "' AND edad=" + edadA + ";");
                
                if(rs.next())
                {
                    stmt.executeUpdate("DELETE FROM alumnos WHERE id=" + idA + " AND nombre='" + nombreA + "' AND edad=" + edadA + ";");
                    label.setForeground(new Color(204,0,0));label.setText("Se muestra alumno eliminado:");
                    model.addRow(new Object[]{idA, nombreA, edadA});
                    JOptionPane.showMessageDialog(this, "Alumno eliminado correctamente.", "Borrar Alumno", JOptionPane.INFORMATION_MESSAGE);
                    System.out.println(" -- Alumno eliminado correctamente.");
                } else {
                    JOptionPane.showMessageDialog(this, "Alumno no encontrado.", "Borrar Alumno", JOptionPane.WARNING_MESSAGE);
                }
            } catch (SQLException ex) {
                JOptionPane.showMessageDialog(this, "Ocurrio una excepción.", "Base de Datos", JOptionPane.ERROR_MESSAGE);
                Logger.getLogger(Ventana.class.getName()).log(Level.SEVERE, null, ex);
            }
        } else {
            JOptionPane.showMessageDialog(this, "Llena correctamente los campos.", "Base de Datos", JOptionPane.WARNING_MESSAGE);
        }
    }//GEN-LAST:event_borrarActionPerformed

    private void verActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_verActionPerformed
        Statement stmt;
        model.setRowCount(0);
        label.setText("");
        try {
            stmt = conn.createStatement();
            ResultSet rs = stmt.executeQuery("SELECT * FROM alumnos;");
            label.setForeground(Color.black);label.setText("Se muestran registros:");
            while (rs.next()) {
                model.addRow(new Object[]{rs.getInt("id"), rs.getString("nombre"), rs.getInt("edad")});
            }
            JOptionPane.showMessageDialog(this, "Se muestran los registros.", "Ver todo", JOptionPane.INFORMATION_MESSAGE);
            System.out.println(" >> Se muestran los registros.");
        } catch (SQLException ex) {
            JOptionPane.showMessageDialog(this, "Ocurrio una excepción.", "Base de Datos", JOptionPane.ERROR_MESSAGE);
            Logger.getLogger(Ventana.class.getName()).log(Level.SEVERE, null, ex);
        }
    }//GEN-LAST:event_verActionPerformed

    private void ageStateChanged(javax.swing.event.ChangeEvent evt) {//GEN-FIRST:event_ageStateChanged
        if ((int) age.getValue() < 0 || (int)age.getValue() > 120)
        {
            JOptionPane.showMessageDialog(this, "Agrega uuna edad válida (0-120).", "Base de Datos", JOptionPane.WARNING_MESSAGE);
            age.setValue(0);
        }
    }//GEN-LAST:event_ageStateChanged

    private void buscarActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_buscarActionPerformed
        if(validar())
        {
            Statement stmt;
            model.setRowCount(0);
            label.setText("");
            try {
                stmt = conn.createStatement();
                
                ResultSet rs = stmt.executeQuery("SELECT * FROM alumnos WHERE id=" + idA + " AND nombre='" + nombreA + "' AND edad=" + edadA + ";");
                
                if(rs.next())
                {
                    label.setForeground(new Color(0,51,204));label.setText("Se muestra alumno encontrado:");
                    model.addRow(new Object[]{idA, nombreA, edadA});
                    JOptionPane.showMessageDialog(this, "Alumno encontrado.", "Buscar Alumno", JOptionPane.INFORMATION_MESSAGE);
                    System.out.println(" >> Alumno encontrado.");
                } else {
                    JOptionPane.showMessageDialog(this, "Alumno no encontrado.", "Buscar Alumno", JOptionPane.WARNING_MESSAGE);
                    System.out.println(" >> Alumno no encontrado.");
                }
            } catch (SQLException ex) {
                JOptionPane.showMessageDialog(this, "Ocurrio una excepción.", "Base de Datos", JOptionPane.ERROR_MESSAGE);
                Logger.getLogger(Ventana.class.getName()).log(Level.SEVERE, null, ex);
            }
        } else {
            JOptionPane.showMessageDialog(this, "Llena correctamente los campos.", "Base de Datos", JOptionPane.WARNING_MESSAGE);
        }
    }//GEN-LAST:event_buscarActionPerformed

    /**
     * @param args the command line arguments
     */
    public static void main(String args[]) {
        /* Set the Nimbus look and feel */
        //<editor-fold defaultstate="collapsed" desc=" Look and feel setting code (optional) ">
        /* If Nimbus (introduced in Java SE 6) is not available, stay with the default look and feel.
         * For details see http://download.oracle.com/javase/tutorial/uiswing/lookandfeel/plaf.html 
         */
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

        /* Create and display the form */
        java.awt.EventQueue.invokeLater(new Runnable() {
            public void run() {
                new Ventana().setVisible(true);
            }
        });
    }

    // Variables declaration - do not modify//GEN-BEGIN:variables
    private javax.swing.JSpinner age;
    private javax.swing.JButton borrar;
    private javax.swing.JButton buscar;
    private javax.swing.JTextField id;
    private javax.swing.JLabel jLabel1;
    private javax.swing.JLabel jLabel2;
    private javax.swing.JLabel jLabel3;
    private javax.swing.JLabel jLabel4;
    private javax.swing.JLabel jLabel5;
    private javax.swing.JPanel jPanel1;
    private javax.swing.JPanel jPanel2;
    private javax.swing.JPanel jPanel4;
    private javax.swing.JPanel jPanel5;
    private javax.swing.JPanel jPanel6;
    private javax.swing.JPanel jPanel7;
    private javax.swing.JPanel jPanel9;
    private javax.swing.JScrollPane jScrollPane1;
    private javax.swing.JLabel label;
    private javax.swing.JTextField name;
    private javax.swing.JButton registrar;
    private javax.swing.JTable tabla;
    private javax.swing.JButton ver;
    // End of variables declaration//GEN-END:variables
}
