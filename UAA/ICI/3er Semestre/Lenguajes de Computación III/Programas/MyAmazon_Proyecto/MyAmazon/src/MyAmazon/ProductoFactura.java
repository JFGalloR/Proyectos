package MyAmazon;

import MyAmazon.Fonts.Fonts;

public class ProductoFactura extends javax.swing.JPanel {

    public ProductoFactura(String producto, int cant, float precio) {
        initComponents();
        Producto.setText(producto);
        Cantidad.setText(Integer.toString(cant));
        Precio.setText("$" + Float.toString(precio));
    }

    @SuppressWarnings("unchecked")
    // <editor-fold defaultstate="collapsed" desc="Generated Code">//GEN-BEGIN:initComponents
    private void initComponents() {

        Precio = new javax.swing.JLabel();
        Cantidad = new javax.swing.JLabel();
        Label = new javax.swing.JLabel();
        Producto = new javax.swing.JLabel();
        Background = new javax.swing.JLabel();

        setBackground(new java.awt.Color(255, 255, 255));
        setPreferredSize(new java.awt.Dimension(500, 50));
        setLayout(null);

        Precio.setFont(new Fonts().setFonts(Fonts.EMBER_LT, 0, 16));
        add(Precio);
        Precio.setBounds(380, 10, 120, 30);

        Cantidad.setFont(new Fonts().setFonts(Fonts.EMBER_LT, 0, 16));
        add(Cantidad);
        Cantidad.setBounds(320, 10, 40, 30);

        Label.setFont(new Fonts().setFonts(Fonts.EMBER_RG, 0, 16));
        Label.setText("Cantidad:");
        add(Label);
        Label.setBounds(250, 10, 70, 30);

        Producto.setFont(new Fonts().setFonts(Fonts.EMBER_RG, 0, 20));
        Producto.setText("Nombre del producto");
        add(Producto);
        Producto.setBounds(20, 10, 210, 30);

        Background.setIcon(new javax.swing.ImageIcon(getClass().getResource("/MyAmazon/Images/PanelFactProd.png"))); // NOI18N
        add(Background);
        Background.setBounds(0, 0, 500, 50);
    }// </editor-fold>//GEN-END:initComponents


    // Variables declaration - do not modify//GEN-BEGIN:variables
    private javax.swing.JLabel Background;
    private javax.swing.JLabel Cantidad;
    private javax.swing.JLabel Label;
    private javax.swing.JLabel Precio;
    private javax.swing.JLabel Producto;
    // End of variables declaration//GEN-END:variables
}
