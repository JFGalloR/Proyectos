package MyAmazon;

import MyAmazon.MessageBox.MessageBox;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;

public class MyAmazon extends javax.swing.JFrame {
    String jdbcUrl = "jdbc:mariadb://localhost:3306";
    String username = "root";
    String password = "";
    static String dBase = "MyAmazon";
    static String clientes = "Clientes";
    static String inventario = "Inventario";
    static String movimientos = "Movimientos";
    static String carrito = "Carrito";
    static Connection conn;
    
    public MyAmazon() {
        initComponents();
        generarBase();
        pantallaInicio();
    }

    public void generarBase() {
        // Base de datos.
        try {
            conn = DriverManager.getConnection(jdbcUrl, username, password);
            Statement stmt = conn.createStatement();
            
            // Se verifica la base de datos. -----------------------------------
            ResultSet resultSet = stmt.executeQuery("SHOW DATABASES LIKE '" + dBase + "';");
            
            if (resultSet.next()) {
                System.out.println(" >> La base de datos \"" + dBase + "\" ya existe.");
            } else {
                stmt.executeUpdate("CREATE DATABASE " + dBase + ";");
                System.out.println(" ++ La base de datos \"" + dBase + "\" ha sido creada.");
            }
            
            stmt.executeUpdate("USE " + dBase + ";");
            
            // Se verifica la tabla1. ------------------------------------------
            resultSet = stmt.executeQuery("SHOW TABLES LIKE '" + clientes + "';");
            
            if (resultSet.next()) {
                System.out.println(" >> La tabla \"" + clientes + "\" ya existe.");
            } else {
                
                    stmt.executeUpdate("CREATE TABLE " + clientes + " "
                            + "(clave INT AUTO_INCREMENT PRIMARY KEY, usuario varchar(255) COLLATE utf8_bin, contraseña varchar(255) COLLATE utf8_bin);");
                    System.out.println(" ++ La tabla \"" + clientes + "\" ha sido creada.");
            }
            
            // Se verifica la tabla2. ------------------------------------------
            resultSet = stmt.executeQuery("SHOW TABLES LIKE '" + inventario + "';");
            
            if (resultSet.next()) {
                System.out.println(" >> La tabla \"" + inventario + "\" ya existe.");
            } else {
                
                    stmt.executeUpdate("CREATE TABLE " + inventario + " "
                            + "(clave INT AUTO_INCREMENT PRIMARY KEY, producto varchar(255), imagen varchar(255), categoria varchar(255), cantidad int, precio float);");
                    System.out.println(" ++ La tabla \"" + inventario + "\" ha sido creada.");
            }
            
            // Se verifica la tabla3. ------------------------------------------
            resultSet = stmt.executeQuery("SHOW TABLES LIKE '" + movimientos + "';");
            
            if (resultSet.next()) {
                System.out.println(" >> La tabla \"" + movimientos + "\" ya existe.");
            } else {
                    stmt.executeUpdate("CREATE TABLE " + movimientos + " "
                            + "(clave_movimiento INT AUTO_INCREMENT PRIMARY KEY, clave_usuario int, clave_producto int, producto varchar(255), cantidad int, precio float, direccion text, fecha_hora datetime);");
                    System.out.println(" ++ La tabla \"" + movimientos + "\" ha sido creada.");
            }
            
            // Se verifica la tabla4. ------------------------------------------
            resultSet = stmt.executeQuery("SHOW TABLES LIKE '" + carrito + "';");
            
            if (resultSet.next()) {
                System.out.println(" >> La tabla \"" + carrito + "\" ya existe.");
            } else {
                
                    stmt.executeUpdate("CREATE TABLE " + carrito + " "
                            + "(clave_carrito INT AUTO_INCREMENT PRIMARY KEY, clave_usuario int, clave_producto int, cantidad int);");
                    System.out.println(" ++ La tabla \"" + carrito + "\" ha sido creada.");
            }
        } catch (SQLException ex) {
            MessageBox.showMB("No se pudo acceder.", "No se pudo acceder a la base de datos.", MessageBox.ICON_ERROR);
            System.exit(1);
        }
    }

    public void pantallaInicio() {
        Inicio pI = new Inicio();
        pI.setSize(1150, 648);
        pI.setLocation(0, 0);
        Panel.removeAll();
        Panel.add(pI);
        Panel.revalidate();
        Panel.repaint();
    }

    @SuppressWarnings("unchecked")
    // <editor-fold defaultstate="collapsed" desc="Generated Code">//GEN-BEGIN:initComponents
    private void initComponents() {

        Panel = new javax.swing.JPanel();

        setDefaultCloseOperation(javax.swing.WindowConstants.EXIT_ON_CLOSE);
        setTitle("My Amazon");
        setIconImage(new javax.swing.ImageIcon(getClass().getResource("Icons/Icon.png")).getImage());
        setResizable(false);

        Panel.setCursor(new java.awt.Cursor(java.awt.Cursor.DEFAULT_CURSOR));

        javax.swing.GroupLayout PanelLayout = new javax.swing.GroupLayout(Panel);
        Panel.setLayout(PanelLayout);
        PanelLayout.setHorizontalGroup(
            PanelLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGap(0, 1150, Short.MAX_VALUE)
        );
        PanelLayout.setVerticalGroup(
            PanelLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGap(0, 648, Short.MAX_VALUE)
        );

        javax.swing.GroupLayout layout = new javax.swing.GroupLayout(getContentPane());
        getContentPane().setLayout(layout);
        layout.setHorizontalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addComponent(Panel, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
        );
        layout.setVerticalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addComponent(Panel, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
        );

        pack();
        setLocationRelativeTo(null);
    }// </editor-fold>//GEN-END:initComponents

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
            java.util.logging.Logger.getLogger(MyAmazon.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (InstantiationException ex) {
            java.util.logging.Logger.getLogger(MyAmazon.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (IllegalAccessException ex) {
            java.util.logging.Logger.getLogger(MyAmazon.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (javax.swing.UnsupportedLookAndFeelException ex) {
            java.util.logging.Logger.getLogger(MyAmazon.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        }
        //</editor-fold>

        /* Create and display the form */
        java.awt.EventQueue.invokeLater(new Runnable() {
            public void run() {
                new MyAmazon().setVisible(true);
            }
        });
    }

    // Variables declaration - do not modify//GEN-BEGIN:variables
    public static javax.swing.JPanel Panel;
    // End of variables declaration//GEN-END:variables
}
