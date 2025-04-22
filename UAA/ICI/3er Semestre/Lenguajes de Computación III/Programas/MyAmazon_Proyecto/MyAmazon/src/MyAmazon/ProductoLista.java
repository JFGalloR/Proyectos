package MyAmazon;

import MyAmazon.Fonts.Fonts;
import MyAmazon.MessageBox.MessageBox;
import java.awt.Image;
import java.sql.Connection;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;
import javax.swing.ImageIcon;

public class ProductoLista extends javax.swing.JPanel {

    Connection conn;
    Carrito carrito;
    int clave_u;
    int clave_p;
    int cant_c;
    int cant_i;

    boolean c = true;

    public ProductoLista(Carrito carrito, int clave, String producto, String imagen, int cant_i, int cant_c, float precio) {
        initComponents();
        this.conn = MyAmazon.conn;
        this.carrito = carrito;
        this.clave_u = Compras.clave;
        this.clave_p = clave;
        this.cant_c = cant_c;
        this.cant_i = cant_i;
        Producto.setText(producto);

        ImageIcon icon;
        icon = new ImageIcon(getClass().getResource(imagen == null ? "/MyAmazon/Images/Products/NoImage.png" : imagen));
        int newWidth;
        int newHeight;

        if (icon.getIconWidth() > icon.getIconHeight()) {
            newHeight = icon.getIconHeight() * 50 / icon.getIconWidth();
            newWidth = 50;
        } else {
            newWidth = icon.getIconWidth() * 50 / icon.getIconHeight();
            newHeight = 50;
        }

        icon = new ImageIcon(icon.getImage().getScaledInstance(newWidth, newHeight, Image.SCALE_SMOOTH));
        Imagen.setIcon(icon);
        for (int i = 2; i <= cant_i; i++) {
            Cantidad.addItem(Integer.toString(i));
        }

        Cantidad.setSelectedIndex(cant_c - 1);
        Precio.setText("$" + Float.toString(precio));
    }

    @SuppressWarnings("unchecked")
    // <editor-fold defaultstate="collapsed" desc="Generated Code">//GEN-BEGIN:initComponents
    private void initComponents() {

        Precio = new javax.swing.JLabel();
        Cantidad = new javax.swing.JComboBox<>();
        Producto = new javax.swing.JLabel();
        Imagen = new javax.swing.JLabel();
        Btn = new javax.swing.JLabel();
        Background = new javax.swing.JLabel();

        setBackground(new java.awt.Color(255, 255, 255));
        setPreferredSize(new java.awt.Dimension(420, 60));
        setLayout(null);

        Precio.setBackground(new java.awt.Color(255, 255, 255));
        Precio.setFont(new Fonts().setFonts(Fonts.EMBER_LT, 0, 14));
        add(Precio);
        Precio.setBounds(340, 20, 70, 20);

        Cantidad.setModel(new javax.swing.DefaultComboBoxModel<>(new String[] { "1" }));
        Cantidad.setFocusable(false);
        Cantidad.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                CantidadActionPerformed(evt);
            }
        });
        add(Cantidad);
        Cantidad.setBounds(280, 20, 50, 22);

        Producto.setFont(new Fonts().setFonts(Fonts.EMBER_RG, 0, 16));
        Producto.setText("Nombre del producto");
        add(Producto);
        Producto.setBounds(110, 16, 160, 30);
        add(Imagen);
        Imagen.setBounds(40, 5, 50, 50);

        Btn.setBackground(new java.awt.Color(255, 255, 255));
        Btn.setIcon(new javax.swing.ImageIcon(getClass().getResource("/MyAmazon/Images/ButtonsMenuCuenta/BtnQuitar.png"))); // NOI18N
        Btn.addMouseMotionListener(new java.awt.event.MouseMotionAdapter() {
            public void mouseMoved(java.awt.event.MouseEvent evt) {
                BtnMouseMoved(evt);
            }
        });
        Btn.addMouseListener(new java.awt.event.MouseAdapter() {
            public void mouseClicked(java.awt.event.MouseEvent evt) {
                BtnMouseClicked(evt);
            }
            public void mouseExited(java.awt.event.MouseEvent evt) {
                BtnMouseExited(evt);
            }
        });
        add(Btn);
        Btn.setBounds(13, 23, 14, 14);

        Background.setIcon(new javax.swing.ImageIcon(getClass().getResource("/MyAmazon/Images/PanelLisProd.png"))); // NOI18N
        Background.setMaximumSize(new java.awt.Dimension(430, 60));
        Background.setMinimumSize(new java.awt.Dimension(430, 60));
        Background.setPreferredSize(new java.awt.Dimension(430, 60));
        add(Background);
        Background.setBounds(0, 0, 420, 60);
    }// </editor-fold>//GEN-END:initComponents

    private void BtnMouseExited(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_BtnMouseExited
        Btn.setIcon(new javax.swing.ImageIcon(getClass().getResource("/MyAmazon/Images/ButtonsMenuCuenta/BtnQuitar.png")));
    }//GEN-LAST:event_BtnMouseExited

    private void BtnMouseMoved(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_BtnMouseMoved
        Btn.setIcon(new javax.swing.ImageIcon(getClass().getResource("/MyAmazon/Images/ButtonsMenuCuenta/BtnQuitar_H.png")));
    }//GEN-LAST:event_BtnMouseMoved

    private void BtnMouseClicked(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_BtnMouseClicked
        try {
            Statement stmt = conn.createStatement();

            ResultSet resultSet = stmt.executeQuery("SELECT * FROM " + MyAmazon.carrito + " WHERE clave_usuario = " + clave_u
                    + " AND clave_producto = " + clave_p + ";");

            if (resultSet.next()) {
                stmt.executeUpdate("DELETE FROM " + MyAmazon.carrito + "  WHERE clave_usuario = " + clave_u
                        + " AND clave_producto = " + clave_p + ";");
            }
            MessageBox.showMB("Eliminado del carrito.", "Producto eliminado del carrito.", MessageBox.ICON_CHECKED);
            carrito.scroll = carrito.ScrollPane.getVerticalScrollBar().getValue();
            carrito.actualizarCarrito();
            System.out.println("   -- Se elimino del carrito.");
        } catch (SQLException ex) {
            MessageBox.showMB("No se pudo acceder.", "No se pudo acceder a la base de datos.", MessageBox.ICON_ERROR);
        }
    }//GEN-LAST:event_BtnMouseClicked

    private void CantidadActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_CantidadActionPerformed
        if ((int) Cantidad.getSelectedIndex() + 1 != cant_c) {
            try {
                Statement stmt = conn.createStatement();

                ResultSet resultSet = stmt.executeQuery("SELECT * FROM " + MyAmazon.carrito + " WHERE clave_usuario = " + clave_u
                        + " AND clave_producto = " + clave_p + ";");

                if (resultSet.next()) {
                    stmt.executeUpdate("UPDATE " + MyAmazon.carrito + " SET cantidad = " + (Cantidad.getSelectedIndex() + 1) + "  WHERE clave_usuario = " + clave_u
                            + " AND clave_producto = " + clave_p + ";");
                    System.out.println("   ** Se modifico del carrito.");
                }
                carrito.scroll = carrito.ScrollPane.getVerticalScrollBar().getValue();
                carrito.verificarStock();
                carrito.actualizarCarrito();
            } catch (SQLException ex) {
                MessageBox.showMB("No se pudo acceder.", "No se pudo acceder a la base de datos.", MessageBox.ICON_ERROR);
            }
        }
    }//GEN-LAST:event_CantidadActionPerformed


    // Variables declaration - do not modify//GEN-BEGIN:variables
    private javax.swing.JLabel Background;
    private javax.swing.JLabel Btn;
    private javax.swing.JComboBox<String> Cantidad;
    private javax.swing.JLabel Imagen;
    private javax.swing.JLabel Precio;
    private javax.swing.JLabel Producto;
    // End of variables declaration//GEN-END:variables
}
