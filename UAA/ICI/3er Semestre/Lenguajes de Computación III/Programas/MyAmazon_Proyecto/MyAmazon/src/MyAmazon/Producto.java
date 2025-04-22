package MyAmazon;

import MyAmazon.Fonts.Fonts;
import MyAmazon.MessageBox.MessageBox;
import java.awt.Image;
import java.sql.Connection;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;
import java.text.ParseException;
import javax.swing.ImageIcon;

public class Producto extends javax.swing.JPanel {

    Connection conn;
    Compras cmp;
    int min = 0;
    int clave_u;
    int clave_p;
    int cantidad;
    boolean c = true;

    public Producto(Compras cmp, int clave, String producto, String imagen, int cantidad, float precio) {
        initComponents();
        this.cmp = cmp;
        this.conn = MyAmazon.conn;
        this.clave_u = Compras.clave;
        this.clave_p = clave;
        this.cantidad = cantidad;
        Titulo.setText(producto);
        
        ImageIcon icon;
        if (imagen == null) {
            icon = new ImageIcon(getClass().getResource("/MyAmazon/Images/Products/NoImage.png"));
        } else {
            ImageIcon oIcon = new ImageIcon(getClass().getResource(imagen));
            int newWidth;
            int newHeight;
            
            if(oIcon.getIconWidth() > oIcon.getIconHeight())
            {
                newHeight = oIcon.getIconHeight()* 210 / oIcon.getIconWidth();
                newWidth = 210;
            }else
            {
                newWidth = oIcon.getIconWidth() * 160 / oIcon.getIconHeight();
                newHeight = 160;
            }
            
            icon = new ImageIcon(oIcon.getImage().getScaledInstance(newWidth, newHeight, Image.SCALE_SMOOTH));
        }
        Imagen.setIcon(icon);

        Precio.setText("$" + Float.toString(precio));
    }

    @SuppressWarnings("unchecked")
    // <editor-fold defaultstate="collapsed" desc="Generated Code">//GEN-BEGIN:initComponents
    private void initComponents() {

        Btn = new javax.swing.JLabel();
        Cantidad = new javax.swing.JSpinner();
        Precio = new javax.swing.JLabel();
        Titulo = new javax.swing.JTextArea();
        Imagen = new javax.swing.JLabel();
        Background = new javax.swing.JLabel();

        setBackground(new java.awt.Color(255, 255, 255));
        setOpaque(false);
        setPreferredSize(new java.awt.Dimension(250, 350));
        setLayout(null);

        Btn.setHorizontalAlignment(javax.swing.SwingConstants.CENTER);
        Btn.setIcon(new javax.swing.ImageIcon(getClass().getResource("/MyAmazon/Images/ButtonsProducto/Btn.png"))); // NOI18N
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
        Btn.setBounds(120, 300, 100, 30);

        Cantidad.setFont(new Fonts().setFonts(Fonts.EMBER_LT, 0, 10)
        );
        Cantidad.setFocusable(false);
        Cantidad.setRequestFocusEnabled(false);
        Cantidad.setValue(0);
        Cantidad.addChangeListener(new javax.swing.event.ChangeListener() {
            public void stateChanged(javax.swing.event.ChangeEvent evt) {
                CantidadStateChanged(evt);
            }
        });
        add(Cantidad);
        Cantidad.setBounds(30, 300, 64, 22);

        Precio.setFont(new Fonts().setFonts(Fonts.EMBER_LT, 0, 22));
        Precio.setText("$0.0");
        add(Precio);
        Precio.setBounds(30, 260, 190, 20);

        Titulo.setEditable(false);
        Titulo.setColumns(20);
        Titulo.setFont(new Fonts().setFonts(Fonts.EMBER_RG, 0, 24));
        Titulo.setLineWrap(true);
        Titulo.setRows(5);
        Titulo.setText("Nombre del producto");
        Titulo.setWrapStyleWord(true);
        Titulo.setBorder(null);
        Titulo.setOpaque(false);
        Titulo.setRequestFocusEnabled(false);
        add(Titulo);
        Titulo.setBounds(30, 190, 190, 70);

        Imagen.setBackground(new java.awt.Color(248, 248, 248));
        Imagen.setHorizontalAlignment(javax.swing.SwingConstants.CENTER);
        Imagen.setIcon(new javax.swing.ImageIcon(getClass().getResource("/MyAmazon/Images/Products/NoImage.png"))); // NOI18N
        Imagen.setOpaque(true);
        Imagen.addMouseListener(new java.awt.event.MouseAdapter() {
            public void mouseClicked(java.awt.event.MouseEvent evt) {
                ImagenMouseClicked(evt);
            }
        });
        add(Imagen);
        Imagen.setBounds(20, 20, 210, 160);

        Background.setIcon(new javax.swing.ImageIcon(getClass().getResource("/MyAmazon/Images/PanelProducto.png"))); // NOI18N
        add(Background);
        Background.setBounds(0, 0, 250, 350);
    }// </editor-fold>//GEN-END:initComponents

    private void BtnMouseExited(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_BtnMouseExited
        if(Btn.isEnabled())
            Btn.setIcon(new javax.swing.ImageIcon(getClass().getResource("/MyAmazon/Images/ButtonsProducto/Btn.png")));
    }//GEN-LAST:event_BtnMouseExited

    private void BtnMouseMoved(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_BtnMouseMoved
        if(Btn.isEnabled())
            Btn.setIcon(new javax.swing.ImageIcon(getClass().getResource("/MyAmazon/Images/ButtonsProducto/Btn_H.png")));
    }//GEN-LAST:event_BtnMouseMoved

    private void CantidadStateChanged(javax.swing.event.ChangeEvent evt) {//GEN-FIRST:event_CantidadStateChanged
        if (cantidad == 0) {
            MessageBox.showMB("Agregar al carrito.", "Ya no hay inventario disponible de este artículo.", MessageBox.ICON_INFO);
            Cantidad.setValue(0);
        } else if ((int) Cantidad.getValue() < 0) {
            Cantidad.setValue(0);
        } else if ((int) Cantidad.getValue() > cantidad + 1) {
            Cantidad.setValue(cantidad);
            c = false;
        } else if ((int) Cantidad.getValue() > cantidad) {
            Cantidad.setValue(cantidad);
        }
    }//GEN-LAST:event_CantidadStateChanged

    private void ImagenMouseClicked(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_ImagenMouseClicked
        this.setComponentZOrder(Imagen, 5);
    }//GEN-LAST:event_ImagenMouseClicked

    private void BtnMouseClicked(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_BtnMouseClicked
        Btn.requestFocus();
        try {
            Cantidad.commitEdit();
            if (Btn.isEnabled()) {
                if ((int) Cantidad.getValue() > 0 && (int) Cantidad.getValue() <= cantidad && c) {
                    try {
                        Statement stmt = conn.createStatement();
                        
                        ResultSet resultSet = stmt.executeQuery("SELECT * FROM " + MyAmazon.carrito + " WHERE clave_usuario = " + clave_u +
                                " AND clave_producto = " + clave_p + ";");
                        
                        if(resultSet.next())
                        {
                            int pCant = resultSet.getInt("cantidad");
                            stmt.executeUpdate("UPDATE " + MyAmazon.carrito + " SET cantidad = " + (pCant + (int) Cantidad.getValue()) +
                                    " WHERE clave_usuario = " + clave_u + " AND clave_producto = " + clave_p + ";");
                        }else 
                        {
                            stmt.executeUpdate("INSERT INTO " + MyAmazon.carrito + "(clave_usuario, clave_producto, cantidad) "  
                                    + " VALUES (" + clave_u + ", " + clave_p + ", " + (int) Cantidad.getValue() + ");");
                        }
                        
                        System.out.println("   ++ Se agrego producto al carrito.");
                        cmp.actualizar();
                        MessageBox.showMB("Agregado al carrito.", (int) Cantidad.getValue() + " unidades agregadas al carrito.", MessageBox.ICON_CHECKED);
                        cantidad -= (int) Cantidad.getValue();
                        Cantidad.setValue(0);
                        if (cantidad == 0) {
                            Btn.setEnabled(false);
                        }
                    } catch (SQLException ex) {
                        MessageBox.showMB("No se pudo acceder.", "No se pudo acceder a la base de datos.", MessageBox.ICON_ERROR);
                    }
                } else {
                    MessageBox.showMB("Agregar al carrito.", "Ingresa una cantidad válida de unidades.", MessageBox.ICON_WARNIGN);
                }
                c = true;
            }
        } catch (ParseException ex) {
            MessageBox.showMB("Agregar al carrito.", "Ingresa una cantidad válida de unidades.", MessageBox.ICON_WARNIGN);
        }
    }//GEN-LAST:event_BtnMouseClicked


    // Variables declaration - do not modify//GEN-BEGIN:variables
    private javax.swing.JLabel Background;
    private javax.swing.JLabel Btn;
    private javax.swing.JSpinner Cantidad;
    private javax.swing.JLabel Imagen;
    private javax.swing.JLabel Precio;
    private javax.swing.JTextArea Titulo;
    // End of variables declaration//GEN-END:variables
}
