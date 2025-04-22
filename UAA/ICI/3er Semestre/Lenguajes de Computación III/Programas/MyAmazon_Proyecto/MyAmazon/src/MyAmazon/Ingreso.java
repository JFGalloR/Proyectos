package MyAmazon;

import MyAmazon.Fonts.Fonts;
import MyAmazon.MessageBox.MessageBox;
import java.sql.Connection;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;
import javax.swing.ImageIcon;
import javax.swing.JLabel;

public class Ingreso extends javax.swing.JPanel {

    Connection conn;
    String usuario;

    public Ingreso() {
        initComponents();
        this.conn = MyAmazon.conn;
    }

    @SuppressWarnings("unchecked")
    // <editor-fold defaultstate="collapsed" desc="Generated Code">//GEN-BEGIN:initComponents
    private void initComponents() {

        BtnReg = new javax.swing.JLabel();
        Label4 = new javax.swing.JLabel();
        BtnIng = new javax.swing.JLabel();
        Contraseña = new javax.swing.JPasswordField();
        Label3 = new javax.swing.JLabel();
        Usuario = new javax.swing.JTextField();
        Label2 = new javax.swing.JLabel();
        Label1 = new javax.swing.JLabel();
        Background = new javax.swing.JLabel();

        setBackground(new java.awt.Color(255, 255, 255));
        setLayout(null);

        BtnReg.setHorizontalAlignment(javax.swing.SwingConstants.CENTER);
        BtnReg.setIcon(new javax.swing.ImageIcon(getClass().getResource("/MyAmazon/Images/ButtonsIngReg/IngBtnReg.png"))); // NOI18N
        BtnReg.setName("BtnReg"); // NOI18N
        BtnReg.addMouseMotionListener(new java.awt.event.MouseMotionAdapter() {
            public void mouseMoved(java.awt.event.MouseEvent evt) {
                BtnMouseMoved(evt);
            }
        });
        BtnReg.addMouseListener(new java.awt.event.MouseAdapter() {
            public void mouseClicked(java.awt.event.MouseEvent evt) {
                BtnRegMouseClicked(evt);
            }
            public void mouseExited(java.awt.event.MouseEvent evt) {
                BtnMouseExited(evt);
            }
        });
        add(BtnReg);
        BtnReg.setBounds(90, 420, 240, 52);

        Label4.setFont(new Fonts().setFonts(Fonts.EMBER_LT, 0, 12));
        Label4.setHorizontalAlignment(javax.swing.SwingConstants.CENTER);
        Label4.setText("- ¿Eres nuevo en MyAmazon? -");
        add(Label4);
        Label4.setBounds(100, 390, 220, 20);

        BtnIng.setHorizontalAlignment(javax.swing.SwingConstants.CENTER);
        BtnIng.setIcon(new javax.swing.ImageIcon(getClass().getResource("/MyAmazon/Images/ButtonsIngReg/IngBtnIng.png"))); // NOI18N
        BtnIng.setName("BtnIng"); // NOI18N
        BtnIng.addMouseMotionListener(new java.awt.event.MouseMotionAdapter() {
            public void mouseMoved(java.awt.event.MouseEvent evt) {
                BtnMouseMoved(evt);
            }
        });
        BtnIng.addMouseListener(new java.awt.event.MouseAdapter() {
            public void mouseClicked(java.awt.event.MouseEvent evt) {
                BtnIngMouseClicked(evt);
            }
            public void mouseExited(java.awt.event.MouseEvent evt) {
                BtnMouseExited(evt);
            }
        });
        add(BtnIng);
        BtnIng.setBounds(90, 320, 240, 52);

        Contraseña.setFont(new Fonts().setFonts(Fonts.EMBER_LT, 0, 14));
        add(Contraseña);
        Contraseña.setBounds(50, 200, 330, 30);

        Label3.setFont(new Fonts().setFonts(Fonts.EMBER_RG, 0, 18));
        Label3.setText("Ingresa contraseña:");
        add(Label3);
        Label3.setBounds(50, 160, 250, 40);

        Usuario.setFont(new Fonts().setFonts(Fonts.EMBER_LT, 0, 14));
        add(Usuario);
        Usuario.setBounds(50, 130, 330, 30);

        Label2.setFont(new Fonts().setFonts(Fonts.EMBER_RG, 0, 18));
        Label2.setText("Ingresa usuario:");
        add(Label2);
        Label2.setBounds(50, 90, 250, 40);

        Label1.setFont(new Fonts().setFonts(Fonts.EMBER_RG, 0, 36));
        Label1.setText("Iniciar sesión");
        add(Label1);
        Label1.setBounds(40, 30, 250, 50);

        Background.setIcon(new javax.swing.ImageIcon(getClass().getResource("/MyAmazon/Images/PanelIngReg.png"))); // NOI18N
        add(Background);
        Background.setBounds(0, 0, 430, 380);
    }// </editor-fold>//GEN-END:initComponents

    private void compras() {
        try {
            Statement stmt = conn.createStatement();
            ResultSet resultSet = stmt.executeQuery("SELECT * FROM " + MyAmazon.clientes + " WHERE usuario = '" + usuario + "';");

            if (resultSet.next()) {
                Compras cmp = new Compras(resultSet.getInt("clave"));
                cmp.setSize(1150, 648);
                cmp.setLocation(0, 0);
                MyAmazon.Panel.removeAll();
                MyAmazon.Panel.add(cmp);
                MyAmazon.Panel.revalidate();
                MyAmazon.Panel.repaint();
            }
            
        } catch (SQLException ex) {
            MessageBox.showMB("No se pudo acceder.", "No se pudo acceder a la base de datos.", MessageBox.ICON_ERROR);
        }
    }

    private boolean validar() {
        if (Usuario.getText().isBlank() && Contraseña.getText().isBlank()) {
            MessageBox.showMB("Ingresar a\ncuenta.", "Ingresa nombre de usuario y contraseña.", MessageBox.ICON_WARNIGN);
            return false;
        } else if (Usuario.getText().isBlank()) {
            MessageBox.showMB("Ingresar a cuenta.", "Ingresa nombre de usuario.", MessageBox.ICON_WARNIGN);
            return false;
        } else if (Contraseña.getText().isBlank()) {
            MessageBox.showMB("Ingresar a cuenta.", "Ingresa la contraseña.", MessageBox.ICON_WARNIGN);
            return false;
        }
        return true;
    }

    private void BtnMouseExited(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_BtnMouseExited
        JLabel btn = (JLabel) evt.getSource();
        btn.setIcon(new ImageIcon(getClass().getResource("/MyAmazon/Images/ButtonsIngReg/Ing" + btn.getName() + ".png")));
    }//GEN-LAST:event_BtnMouseExited

    private void BtnMouseMoved(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_BtnMouseMoved
        JLabel btn = (JLabel) evt.getSource();
        btn.setIcon(new ImageIcon(getClass().getResource("/MyAmazon/Images/ButtonsIngReg/Ing" + btn.getName() + "_H.png")));
    }//GEN-LAST:event_BtnMouseMoved

    private void BtnIngMouseClicked(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_BtnIngMouseClicked
        if (validar()) {
            try {
                Statement stmt = conn.createStatement();
                ResultSet resultSet = stmt.executeQuery("SELECT * FROM " + MyAmazon.clientes + " WHERE usuario = '" + Usuario.getText() + "';");
                // Se verifica si ya está registrado el usuario.
                if (resultSet.next()) {
                    resultSet = stmt.executeQuery("SELECT * FROM " + MyAmazon.clientes + " WHERE usuario = '" + Usuario.getText()
                            + "' AND contraseña = '" + Contraseña.getText() + "';");
                    // Se verifica la contraseña.
                    if (resultSet.next()) {
                        System.out.println("   ** Se ingreso a la cuenta de Usuario: \"" + Usuario.getText() + "\".");
                        this.usuario = Usuario.getText();
                        Usuario.setText("");Contraseña.setText("");
                        compras();
                    } else {
                        MessageBox.showMB("Ingresar a cuenta.", "Contraseña incorrecta.", MessageBox.ICON_STOP);
                    }
                } else {
                    MessageBox.showMB("Ingresar a cuenta.", "No existe una cuenta con ese nombre de usuario.", MessageBox.ICON_ERROR);
                }
            } catch (SQLException ex) {
                MessageBox.showMB("No se pudo acceder.", "No se pudo acceder a la base de datos.", MessageBox.ICON_ERROR);
            }
        }
    }//GEN-LAST:event_BtnIngMouseClicked

    private void BtnRegMouseClicked(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_BtnRegMouseClicked
        IdenReg ir = new IdenReg(false);
        ir.setSize(1150, 648);
        ir.setLocation(0, 0);
        MyAmazon.Panel.removeAll();
        MyAmazon.Panel.add(ir);
        MyAmazon.Panel.revalidate();
        MyAmazon.Panel.repaint();
    }//GEN-LAST:event_BtnRegMouseClicked


    // Variables declaration - do not modify//GEN-BEGIN:variables
    private javax.swing.JLabel Background;
    private javax.swing.JLabel BtnIng;
    private javax.swing.JLabel BtnReg;
    private javax.swing.JPasswordField Contraseña;
    private javax.swing.JLabel Label1;
    private javax.swing.JLabel Label2;
    private javax.swing.JLabel Label3;
    private javax.swing.JLabel Label4;
    private javax.swing.JTextField Usuario;
    // End of variables declaration//GEN-END:variables
}
