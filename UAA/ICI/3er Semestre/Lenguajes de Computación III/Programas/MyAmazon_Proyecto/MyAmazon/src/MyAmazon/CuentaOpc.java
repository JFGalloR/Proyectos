package MyAmazon;

import MyAmazon.Fonts.Fonts;
import MyAmazon.MessageBox.MessageBox;
import java.sql.Connection;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;
import javax.swing.JLabel;

public class CuentaOpc extends javax.swing.JPanel {

    Connection conn;
    int clave;
    String usuario;
    String contraseña;

    public CuentaOpc() {

        this.conn = MyAmazon.conn;
        this.clave = Compras.clave;
        actualizar();
        initComponents();
    }

    private void actualizar() {
        try {
            Statement stmt = conn.createStatement();
            ResultSet resultSet = stmt.executeQuery("SELECT * FROM " + MyAmazon.clientes + " WHERE clave = " + clave + ";");

            if (resultSet.next()) {
                usuario = resultSet.getString("usuario");
                contraseña = resultSet.getString("contraseña");
            }

        } catch (SQLException ex) {
            MessageBox.showMB("No se pudo acceder.", "No se pudo acceder a la base de datos.", MessageBox.ICON_ERROR);
        }

    }

    private boolean validarMod() {
        if (Usuario.getText().isBlank() && Contraseña1.getText().isBlank() && Contraseña1.getText().isBlank()) {
            MessageBox.showMB("Modificar cuenta.", "Llena los datos.", MessageBox.ICON_WARNIGN);
            return false;
        } else if (Usuario.getText().isBlank()) {
            MessageBox.showMB("Modificar cuenta.", "Ingresa nombre de usuario.", MessageBox.ICON_WARNIGN);
            return false;
        } else if (Contraseña1.getText().isBlank()) {
            MessageBox.showMB("Modificar cuenta.", "Ingresa la nueva contraseña.", MessageBox.ICON_WARNIGN);
            return false;
        } else if (Contraseña2.getText().isBlank()) {
            MessageBox.showMB("Modificar cuenta.", "Vuelve a ingresar la nueva contraseña.", MessageBox.ICON_WARNIGN);
            return false;
        } else if (ContraseñaU1.getText().isBlank()) {
            MessageBox.showMB("Modificar cuenta.", "Ingresa la contraseña actual.", MessageBox.ICON_WARNIGN);
            return false;
        } else if (Usuario.getText().length() < 6) {
            MessageBox.showMB("Modificar cuenta.", "El nombre de usuario debe ser mayor a 6\ncaracteres.", MessageBox.ICON_WARNIGN);
            return false;
        } else if (Contraseña1.getText().length() < 6 || Contraseña2.getText().length() < 6) {
            MessageBox.showMB("Modificar cuenta.", "La contraseña debe ser mayor a 6\ncaracteres.", MessageBox.ICON_WARNIGN);
            return false;
        } else if (!Contraseña1.getText().equals(Contraseña2.getText())) {
            MessageBox.showMB("Modificar cuenta.", "Las contraseñas no coinciden.", MessageBox.ICON_WARNIGN);
            return false;
        }
        return true;
    }

    private boolean validarElm() {
        if (ContraseñaU2.getText().isBlank()) {
            MessageBox.showMB("Eliminar cuenta.", "Ingresa la contraseña actual.", MessageBox.ICON_WARNIGN);
            return false;
        }
        return true;
    }

    @SuppressWarnings("unchecked")
    // <editor-fold defaultstate="collapsed" desc="Generated Code">//GEN-BEGIN:initComponents
    private void initComponents() {

        ContraseñaU2 = new javax.swing.JPasswordField();
        Label7 = new javax.swing.JLabel();
        Label6 = new javax.swing.JLabel();
        ContraseñaU1 = new javax.swing.JPasswordField();
        Label5 = new javax.swing.JLabel();
        Contraseña2 = new javax.swing.JPasswordField();
        Label4 = new javax.swing.JLabel();
        Contraseña1 = new javax.swing.JPasswordField();
        Label3 = new javax.swing.JLabel();
        Usuario = new javax.swing.JTextField();
        Label2 = new javax.swing.JLabel();
        Label1 = new javax.swing.JLabel();
        BtnEliminar = new javax.swing.JLabel();
        BtnModificar = new javax.swing.JLabel();

        setBackground(new java.awt.Color(255, 255, 255));
        setLayout(null);

        ContraseñaU2.setFont(new Fonts().setFonts(Fonts.EMBER_LT, 0, 14));
        add(ContraseñaU2);
        ContraseñaU2.setBounds(40, 400, 330, 30);

        Label7.setBackground(new java.awt.Color(255, 255, 255));
        Label7.setFont(new Fonts().setFonts(Fonts.EMBER_RG, 0, 18));
        Label7.setForeground(new java.awt.Color(102, 102, 102));
        Label7.setText("Ingresa contraseña actual:");
        add(Label7);
        Label7.setBounds(40, 360, 250, 40);

        Label6.setFont(new Fonts().setFonts(Fonts.EMBER_RG, 0, 34));
        Label6.setForeground(new java.awt.Color(102, 102, 102));
        Label6.setText("Eliminar cuenta");
        Label6.setToolTipText("");
        add(Label6);
        Label6.setBounds(20, 310, 610, 40);

        ContraseñaU1.setFont(new Fonts().setFonts(Fonts.EMBER_LT, 0, 14));
        add(ContraseñaU1);
        ContraseñaU1.setBounds(390, 110, 330, 30);

        Label5.setBackground(new java.awt.Color(255, 255, 255));
        Label5.setFont(new Fonts().setFonts(Fonts.EMBER_RG, 0, 18));
        Label5.setForeground(new java.awt.Color(102, 102, 102));
        Label5.setText("Ingresa contraseña actual:");
        add(Label5);
        Label5.setBounds(390, 70, 250, 40);

        Contraseña2.setFont(new Fonts().setFonts(Fonts.EMBER_LT, 0, 14));
        Contraseña2.setText(contraseña);
        add(Contraseña2);
        Contraseña2.setBounds(40, 250, 330, 30);

        Label4.setBackground(new java.awt.Color(255, 255, 255));
        Label4.setFont(new Fonts().setFonts(Fonts.EMBER_RG, 0, 18));
        Label4.setForeground(new java.awt.Color(102, 102, 102));
        Label4.setText("Verificar nueva contraseña:");
        add(Label4);
        Label4.setBounds(40, 210, 250, 40);

        Contraseña1.setFont(new Fonts().setFonts(Fonts.EMBER_LT, 0, 14));
        Contraseña1.setText(contraseña);
        add(Contraseña1);
        Contraseña1.setBounds(40, 180, 330, 30);

        Label3.setBackground(new java.awt.Color(255, 255, 255));
        Label3.setFont(new Fonts().setFonts(Fonts.EMBER_RG, 0, 18));
        Label3.setForeground(new java.awt.Color(102, 102, 102));
        Label3.setText("Ingresa nueva contraseña:");
        add(Label3);
        Label3.setBounds(40, 140, 250, 40);

        Usuario.setFont(new Fonts().setFonts(Fonts.EMBER_LT, 0, 14));
        Usuario.setText(usuario);
        add(Usuario);
        Usuario.setBounds(40, 110, 330, 30);

        Label2.setBackground(new java.awt.Color(255, 255, 255));
        Label2.setFont(new Fonts().setFonts(Fonts.EMBER_RG, 0, 18));
        Label2.setForeground(new java.awt.Color(102, 102, 102));
        Label2.setText("Ingresa nuevo nombre de usuario:");
        add(Label2);
        Label2.setBounds(40, 70, 320, 40);

        Label1.setFont(new Fonts().setFonts(Fonts.EMBER_RG, 0, 34));
        Label1.setForeground(new java.awt.Color(102, 102, 102));
        Label1.setText("Modificar Datos");
        Label1.setToolTipText("");
        add(Label1);
        Label1.setBounds(20, 20, 610, 40);

        BtnEliminar.setHorizontalAlignment(javax.swing.SwingConstants.CENTER);
        BtnEliminar.setIcon(new javax.swing.ImageIcon(getClass().getResource("/MyAmazon/Images/ButtonsMenuCuenta/BtnEliminar.png"))); // NOI18N
        BtnEliminar.setName("BtnEliminar"); // NOI18N
        BtnEliminar.addMouseMotionListener(new java.awt.event.MouseMotionAdapter() {
            public void mouseMoved(java.awt.event.MouseEvent evt) {
                BtnMouseMoved(evt);
            }
        });
        BtnEliminar.addMouseListener(new java.awt.event.MouseAdapter() {
            public void mouseClicked(java.awt.event.MouseEvent evt) {
                BtnEliminarMouseClicked(evt);
            }
            public void mouseExited(java.awt.event.MouseEvent evt) {
                BtnMouseExited(evt);
            }
        });
        add(BtnEliminar);
        BtnEliminar.setBounds(470, 400, 170, 40);

        BtnModificar.setHorizontalAlignment(javax.swing.SwingConstants.CENTER);
        BtnModificar.setIcon(new javax.swing.ImageIcon(getClass().getResource("/MyAmazon/Images/ButtonsMenuCuenta/BtnModificar.png"))); // NOI18N
        BtnModificar.setName("BtnModificar"); // NOI18N
        BtnModificar.addMouseMotionListener(new java.awt.event.MouseMotionAdapter() {
            public void mouseMoved(java.awt.event.MouseEvent evt) {
                BtnMouseMoved(evt);
            }
        });
        BtnModificar.addMouseListener(new java.awt.event.MouseAdapter() {
            public void mouseClicked(java.awt.event.MouseEvent evt) {
                BtnModificarMouseClicked(evt);
            }
            public void mouseExited(java.awt.event.MouseEvent evt) {
                BtnMouseExited(evt);
            }
        });
        add(BtnModificar);
        BtnModificar.setBounds(470, 250, 170, 40);
    }// </editor-fold>//GEN-END:initComponents

    private void BtnMouseExited(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_BtnMouseExited
        JLabel btn = (JLabel) evt.getSource();
        btn.setIcon(new javax.swing.ImageIcon(getClass().getResource("/MyAmazon/Images/ButtonsMenuCuenta/" + btn.getName() + ".png")));
    }//GEN-LAST:event_BtnMouseExited

    private void BtnMouseMoved(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_BtnMouseMoved
        JLabel btn = (JLabel) evt.getSource();
        btn.setIcon(new javax.swing.ImageIcon(getClass().getResource("/MyAmazon/Images/ButtonsMenuCuenta/" + btn.getName() + "_H.png")));
    }//GEN-LAST:event_BtnMouseMoved

    private void BtnModificarMouseClicked(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_BtnModificarMouseClicked
        if (validarMod()) {
            try {
                Statement stmt = conn.createStatement();
                ResultSet resultSet = stmt.executeQuery("SELECT * FROM " + MyAmazon.clientes + " WHERE usuario = '" + Usuario.getText()
                        + "' AND clave != " + clave + ";");
                if (resultSet.next()) {
                    MessageBox.showMB("Modificar cuenta.", "Ya existe ese nombre de usuario.", MessageBox.ICON_ERROR);
                } else {
                    resultSet = stmt.executeQuery("SELECT * FROM " + MyAmazon.clientes + " WHERE usuario = '" + usuario
                            + "' AND contraseña = '" + ContraseñaU1.getText() + "';");
                    if (resultSet.next()) {
                        stmt.executeUpdate("UPDATE " + MyAmazon.clientes + " SET usuario = '" + Usuario.getText()
                                + "', contraseña = '" + Contraseña1.getText() + "' WHERE clave = " + clave + ";");
                        ContraseñaU1.setText("");
                        actualizar();
                        MessageBox.showMB("Modificar cuenta.", "Cuenta modificada.", MessageBox.ICON_CHECKMARK);
                    } else {
                        MessageBox.showMB("Modificar cuenta.", "Contraseña incorrecta.", MessageBox.ICON_STOP);
                    }
                }
            } catch (SQLException ex) {
                MessageBox.showMB("No se pudo acceder.", "No se pudo acceder a la base de datos.", MessageBox.ICON_ERROR);
            }
        }
    }//GEN-LAST:event_BtnModificarMouseClicked

    private void BtnEliminarMouseClicked(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_BtnEliminarMouseClicked
        if (validarElm()) {
            try {
                Statement stmt = conn.createStatement();
                ResultSet resultSet = stmt.executeQuery("SELECT * FROM " + MyAmazon.clientes + " WHERE clave = " + clave
                        + " AND contraseña = '" + ContraseñaU2.getText() + "';");
                if (resultSet.next()) {
                    stmt.executeUpdate("DELETE FROM " + MyAmazon.clientes + " WHERE clave = " + clave + ";");
                    stmt.executeUpdate("DELETE FROM " + MyAmazon.carrito + " WHERE clave_usuario = " + clave + ";");
                    stmt.executeUpdate("DELETE FROM " + MyAmazon.movimientos + " WHERE clave_usuario = " + clave + ";");
                    ContraseñaU2.setText("");
                    Inicio pI = new Inicio();
                    pI.setSize(1150, 648);
                    pI.setLocation(0, 0);
                    MyAmazon.Panel.removeAll();
                    MyAmazon.Panel.add(pI);
                    MyAmazon.Panel.revalidate();
                    MyAmazon.Panel.repaint();
                    MessageBox.showMB("Eliminar cuenta.", "Cuenta eliminada. Te esperamos pronto.", MessageBox.ICON_CHECKMARK);
                } else {
                    MessageBox.showMB("Elimianr cuenta.", "Contraseña incorrecta.", MessageBox.ICON_STOP);
                }
            } catch (SQLException ex) {
                MessageBox.showMB("No se pudo acceder.", "No se pudo acceder a la base de datos.", MessageBox.ICON_ERROR);
            }
        }
    }//GEN-LAST:event_BtnEliminarMouseClicked


    // Variables declaration - do not modify//GEN-BEGIN:variables
    private javax.swing.JLabel BtnEliminar;
    private javax.swing.JLabel BtnModificar;
    private javax.swing.JPasswordField Contraseña1;
    private javax.swing.JPasswordField Contraseña2;
    private javax.swing.JPasswordField ContraseñaU1;
    private javax.swing.JPasswordField ContraseñaU2;
    private javax.swing.JLabel Label1;
    private javax.swing.JLabel Label2;
    private javax.swing.JLabel Label3;
    private javax.swing.JLabel Label4;
    private javax.swing.JLabel Label5;
    private javax.swing.JLabel Label6;
    private javax.swing.JLabel Label7;
    private javax.swing.JTextField Usuario;
    // End of variables declaration//GEN-END:variables
}
