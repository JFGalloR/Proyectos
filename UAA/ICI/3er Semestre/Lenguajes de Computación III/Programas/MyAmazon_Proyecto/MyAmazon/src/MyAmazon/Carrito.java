package MyAmazon;

import MyAmazon.Fonts.Fonts;
import MyAmazon.MessageBox.MessageBox;
import java.sql.Connection;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;
import java.time.LocalDateTime;
import java.time.format.DateTimeFormatter;

public class Carrito extends javax.swing.JPanel {

    Connection conn;
    int clave;
    public int scroll = 0;

    public Carrito() {
        this.conn = MyAmazon.conn;
        this.clave = Compras.clave;
        initComponents();
        verificarStock();
        actualizarCarrito();
    }

    public boolean verificarStock() {
        try {
            Statement stmt = conn.createStatement();
            ResultSet resultSet1 = stmt.executeQuery(
                    "SELECT * FROM " + MyAmazon.carrito + " WHERE clave_usuario = " + clave + ";");

            if (resultSet1.next()) {
                boolean cambio = false;
                do {
                    ResultSet resultSet2 = stmt.executeQuery(
                            "SELECT * FROM " + MyAmazon.inventario + " WHERE clave = " + resultSet1.getInt("clave_producto") + ";");
                    resultSet2.next();
                    int cant_c = resultSet1.getInt("cantidad");
                    int cant_p = resultSet2.getInt("cantidad");

                    if (cant_c > cant_p) {
                        cambio = true;
                        stmt.executeUpdate("UPDATE " + MyAmazon.carrito + " SET cantidad = " + cant_p + " WHERE clave_usuario = " + clave
                                + " AND clave_producto = " + resultSet1.getInt("clave_producto") + ";");
                    }

                } while (resultSet1.next());
                if (cambio) {
                    javax.swing.SwingUtilities.invokeLater(() -> {

                        MessageBox.showMB("My Carrito", "Algunos productos cambiaron de stock.", MessageBox.ICON_INFO);;
                    });
                    actualizarCarrito();
                    return false;
                }
            }
        } catch (SQLException ex) {
            MessageBox.showMB("No se pudo acceder.", "No se pudo acceder a la base de datos.", MessageBox.ICON_ERROR);
            return false;
        }
        return true;
    }

    public void actualizarCarrito() {
        try {
            Statement stmt = conn.createStatement();
            ResultSet resultSet1 = stmt.executeQuery(
                    "SELECT * FROM " + MyAmazon.carrito + " WHERE clave_usuario = " + clave + ";");
            Productos.setPreferredSize(new java.awt.Dimension(420, 60));
            Productos.removeAll();

            if (resultSet1.next()) {
                int c = 0;
                float total = 0;
                int aux = Productos.getPreferredSize().width;
                ScrollPane.getVerticalScrollBar().setUnitIncrement(10);

                do {
                    ResultSet resultSet2 = stmt.executeQuery(
                            "SELECT * FROM " + MyAmazon.inventario + " WHERE clave = " + resultSet1.getInt("clave_producto") + ";");
                    resultSet2.next();
                    int clave_p = resultSet2.getInt("clave");
                    String dir = resultSet2.getString("imagen");
                    String prod = resultSet2.getString("producto");
                    int cant_c = resultSet1.getInt("cantidad");
                    int cant_i = resultSet2.getInt("cantidad");
                    float precio = resultSet2.getFloat("precio");
                    total += precio * cant_c;
                    c++;

                    ProductoLista p = new ProductoLista(this, clave_p, prod, dir, cant_i, cant_c, precio);
                    aux -= p.getPreferredSize().width;

                    if (aux < 0) {
                        Productos.setPreferredSize(
                                new java.awt.Dimension(Productos.getPreferredSize().width,
                                        Productos.getPreferredSize().height + p.getPreferredSize().height + 6));
                        aux = Productos.getPreferredSize().width;
                        aux -= p.getPreferredSize().width;
                    }
                    Productos.add(p);
                } while (resultSet1.next());
                Productos.revalidate();
                Productos.repaint();
                CantProd.setText(Integer.toString(c));
                Subtotal.setText("$" + new java.text.DecimalFormat("#,##0.00").format(total));
                Contenedor.setVisible(true);
            } else {
                javax.swing.JLabel l = new javax.swing.JLabel("- Agrega productos al carrito -");
                l.setHorizontalAlignment(javax.swing.JLabel.CENTER);
                l.setPreferredSize(new java.awt.Dimension(300, 100));
                l.setFont(new Fonts().setFonts(Fonts.EMBER_LT, 0, 20));
                Productos.add(l);
                Productos.revalidate();
                Productos.repaint();
                Contenedor.setVisible(false);
                javax.swing.SwingUtilities.invokeLater(() -> {
                    MessageBox.showMB("My Carrito", "No hay productos agregados al carrito.", MessageBox.ICON_INFO);;
                });
            }
        } catch (SQLException ex) {
            MessageBox.showMB("No se pudo acceder.", "No se pudo acceder a la base de datos.", MessageBox.ICON_ERROR);
        }

        javax.swing.SwingUtilities.invokeLater(() -> {
            Productos.revalidate();
            Productos.repaint();
            ScrollPane.getVerticalScrollBar().setValue(scroll);
        });
    }

    private boolean validar() {
        if (Calle.getText().isBlank() || Num.getText().isBlank() || CP.getText().isBlank()) {
            MessageBox.showMB("Realizar compra.", "Llena los datos.", MessageBox.ICON_WARNIGN);
            return false;
        }
        return true;
    }

    @SuppressWarnings("unchecked")
    // <editor-fold defaultstate="collapsed" desc="Generated Code">//GEN-BEGIN:initComponents
    private void initComponents() {

        ScrollPane = new javax.swing.JScrollPane();
        Productos = new javax.swing.JPanel();
        Contenedor = new javax.swing.JPanel();
        Btn = new javax.swing.JLabel();
        Separador = new javax.swing.JSeparator();
        Subtotal = new javax.swing.JLabel();
        Label7 = new javax.swing.JLabel();
        CantProd = new javax.swing.JLabel();
        Label6 = new javax.swing.JLabel();
        Estado = new javax.swing.JComboBox<>();
        Label5 = new javax.swing.JLabel();
        CP = new javax.swing.JTextField();
        Label4 = new javax.swing.JLabel();
        Num = new javax.swing.JTextField();
        Label3 = new javax.swing.JLabel();
        Calle = new javax.swing.JTextField();
        Label2 = new javax.swing.JLabel();
        Label1 = new javax.swing.JLabel();

        setBackground(new java.awt.Color(255, 255, 255));
        setLayout(null);

        ScrollPane.setBorder(null);
        ScrollPane.setHorizontalScrollBarPolicy(javax.swing.ScrollPaneConstants.HORIZONTAL_SCROLLBAR_NEVER);
        ScrollPane.setPreferredSize(new java.awt.Dimension(440, 60));

        Productos.setBackground(new java.awt.Color(255, 255, 255));
        Productos.setPreferredSize(new java.awt.Dimension(420, 90));
        ScrollPane.setViewportView(Productos);

        add(ScrollPane);
        ScrollPane.setBounds(20, 20, 440, 420);

        Contenedor.setBackground(new java.awt.Color(255, 255, 255));
        Contenedor.setLayout(null);

        Btn.setHorizontalAlignment(javax.swing.SwingConstants.CENTER);
        Btn.setIcon(new javax.swing.ImageIcon(getClass().getResource("/MyAmazon/Images/ButtonsMenuCuenta/BtnComprar.png"))); // NOI18N
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
        Contenedor.add(Btn);
        Btn.setBounds(70, 390, 180, 40);
        Contenedor.add(Separador);
        Separador.setBounds(30, 360, 250, 10);

        Subtotal.setFont(new Fonts().setFonts(Fonts.EMBER_HE, 0, 24));
        Subtotal.setVerticalAlignment(javax.swing.SwingConstants.BOTTOM);
        Contenedor.add(Subtotal);
        Subtotal.setBounds(120, 320, 170, 30);

        Label7.setFont(new Fonts().setFonts(Fonts.EMBER_RG, 0, 20));
        Label7.setForeground(new java.awt.Color(102, 102, 102));
        Label7.setText("Subtotal:");
        Label7.setVerticalAlignment(javax.swing.SwingConstants.BOTTOM);
        Contenedor.add(Label7);
        Label7.setBounds(30, 320, 90, 30);

        CantProd.setFont(new Fonts().setFonts(Fonts.EMBER_LT, 0, 14));
        CantProd.setVerticalAlignment(javax.swing.SwingConstants.BOTTOM);
        Contenedor.add(CantProd);
        CantProd.setBounds(110, 290, 90, 30);

        Label6.setFont(new Fonts().setFonts(Fonts.EMBER_RG, 0, 14));
        Label6.setForeground(new java.awt.Color(102, 102, 102));
        Label6.setText("Cant. Prod:");
        Label6.setVerticalAlignment(javax.swing.SwingConstants.BOTTOM);
        Contenedor.add(Label6);
        Label6.setBounds(30, 290, 70, 30);

        Estado.setFont(new Fonts().setFonts(Fonts.EMBER_LT, 0, 10));
        Estado.setModel(new javax.swing.DefaultComboBoxModel<>(new String[] { "Aguascalientes", "Baja California", "Baja California Sur", "Campeche", "CDMX", "Chiapas", "Chihuahua", "Coahuila", "Colima", "Durango", "Estado de México", "Guanajuato", "Guerrero", "Hidalgo", "Jalisco", "Michoacán", "Morelos", "Nayarit", "Nuevo León", "Oaxaca", "Puebla", "Querétaro", "Quintana Roo", "San Luis Potosí", "Sinaloa", "Sonora", "Tabasco", "Tamaulipas", "Tlaxcala", "Veracruz", "Yucatán", "Zacatecas" }));
        Contenedor.add(Estado);
        Estado.setBounds(130, 150, 110, 30);

        Label5.setBackground(new java.awt.Color(255, 255, 255));
        Label5.setFont(new Fonts().setFonts(Fonts.EMBER_RG, 0, 14));
        Label5.setForeground(new java.awt.Color(102, 102, 102));
        Label5.setText("Estado:");
        Contenedor.add(Label5);
        Label5.setBounds(130, 120, 110, 30);

        CP.setFont(new Fonts().setFonts(Fonts.EMBER_LT, 0, 12));
        CP.addKeyListener(new java.awt.event.KeyAdapter() {
            public void keyTyped(java.awt.event.KeyEvent evt) {
                CPKeyTyped(evt);
            }
        });
        Contenedor.add(CP);
        CP.setBounds(50, 150, 70, 30);

        Label4.setBackground(new java.awt.Color(255, 255, 255));
        Label4.setFont(new Fonts().setFonts(Fonts.EMBER_RG, 0, 14));
        Label4.setForeground(new java.awt.Color(102, 102, 102));
        Label4.setText("CP:");
        Contenedor.add(Label4);
        Label4.setBounds(50, 120, 90, 30);

        Num.setFont(new Fonts().setFonts(Fonts.EMBER_LT, 0, 12));
        Contenedor.add(Num);
        Num.setBounds(200, 90, 40, 30);

        Label3.setBackground(new java.awt.Color(255, 255, 255));
        Label3.setFont(new Fonts().setFonts(Fonts.EMBER_RG, 0, 14));
        Label3.setForeground(new java.awt.Color(102, 102, 102));
        Label3.setHorizontalAlignment(javax.swing.SwingConstants.CENTER);
        Label3.setText("#");
        Contenedor.add(Label3);
        Label3.setBounds(180, 90, 20, 30);

        Calle.setFont(new Fonts().setFonts(Fonts.EMBER_LT, 0, 12));
        Contenedor.add(Calle);
        Calle.setBounds(50, 90, 130, 30);

        Label2.setBackground(new java.awt.Color(255, 255, 255));
        Label2.setFont(new Fonts().setFonts(Fonts.EMBER_RG, 0, 14));
        Label2.setForeground(new java.awt.Color(102, 102, 102));
        Label2.setText("Calle:");
        Contenedor.add(Label2);
        Label2.setBounds(50, 60, 130, 30);

        Label1.setFont(new Fonts().setFonts(Fonts.EMBER_RG, 0, 24));
        Label1.setForeground(new java.awt.Color(102, 102, 102));
        Label1.setText("Dirección de entrega:");
        Contenedor.add(Label1);
        Label1.setBounds(20, 10, 250, 40);

        add(Contenedor);
        Contenedor.setBounds(460, 10, 290, 440);
    }// </editor-fold>//GEN-END:initComponents

    private void BtnMouseExited(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_BtnMouseExited
        if (Btn.isEnabled())
            Btn.setIcon(new javax.swing.ImageIcon(getClass().getResource("/MyAmazon/Images/ButtonsMenuCuenta/BtnComprar.png")));
    }//GEN-LAST:event_BtnMouseExited

    private void BtnMouseMoved(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_BtnMouseMoved
        if (Btn.isEnabled())
            Btn.setIcon(new javax.swing.ImageIcon(getClass().getResource("/MyAmazon/Images/ButtonsMenuCuenta/BtnComprar_H.png")));
    }//GEN-LAST:event_BtnMouseMoved

    private void CPKeyTyped(java.awt.event.KeyEvent evt) {//GEN-FIRST:event_CPKeyTyped
        char caracter = evt.getKeyChar();
        if (!Character.isDigit(caracter)) {
            evt.consume();
        }
    }//GEN-LAST:event_CPKeyTyped

    private void BtnMouseClicked(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_BtnMouseClicked
        if (validar()) {
            if (verificarStock()) {
                try {
                    Statement stmt = conn.createStatement();
                    ResultSet resultSet1 = stmt.executeQuery(
                            "SELECT * FROM " + MyAmazon.carrito + " WHERE clave_usuario = " + clave + ";");

                    LocalDateTime ahora = LocalDateTime.now();
                    DateTimeFormatter formatter = DateTimeFormatter.ofPattern("yyyy-MM-dd HH:mm:ss");
                    String f_h = ahora.format(formatter);
                    String dir = Calle.getText() + " #" + Num.getText() + " CP: " + CP.getText() + " Estado: " + Estado.getItemAt(Estado.getSelectedIndex());
                    
                    while (resultSet1.next()) {
                        ResultSet resultSet2 = stmt.executeQuery(
                                "SELECT * FROM " + MyAmazon.inventario + " WHERE clave = " + resultSet1.getInt("clave_producto") + ";");
                        resultSet2.next();
                        int clave_p = resultSet2.getInt("clave");
                        String prod = resultSet2.getString("producto");
                        int cant_c = resultSet1.getInt("cantidad");
                        float precio = resultSet2.getFloat("precio");
                        stmt.executeUpdate("INSERT INTO " + MyAmazon.movimientos
                                + " (clave_usuario, clave_producto, producto, cantidad, precio, direccion, fecha_hora) "
                                + " VALUES (" + clave + ", " + clave_p + ", '" + prod + "', " + cant_c + ", " + precio + ", '" + dir + "', '" + f_h + "');");
                    }
                    stmt.executeQuery(
                                "DELETE FROM " + MyAmazon.carrito + " WHERE clave_usuario = " + clave + ";");
                    System.out.println("   ++ Compra realizada.");
                    MenuCuenta.f = null;
                    MessageBox.showMB("My Amazon.", "Compra realizada exitosamente.", MessageBox.ICON_CHECKED);
                    actualizarCarrito();
                } catch (SQLException ex) {
                    MessageBox.showMB("No se pudo acceder.", "No se pudo acceder a la base de datos.", MessageBox.ICON_ERROR);
                }
            }
        }
    }//GEN-LAST:event_BtnMouseClicked


    // Variables declaration - do not modify//GEN-BEGIN:variables
    private javax.swing.JLabel Btn;
    private javax.swing.JTextField CP;
    private javax.swing.JTextField Calle;
    private javax.swing.JLabel CantProd;
    private javax.swing.JPanel Contenedor;
    private javax.swing.JComboBox<String> Estado;
    private javax.swing.JLabel Label1;
    private javax.swing.JLabel Label2;
    private javax.swing.JLabel Label3;
    private javax.swing.JLabel Label4;
    private javax.swing.JLabel Label5;
    private javax.swing.JLabel Label6;
    private javax.swing.JLabel Label7;
    private javax.swing.JTextField Num;
    private javax.swing.JPanel Productos;
    public javax.swing.JScrollPane ScrollPane;
    private javax.swing.JSeparator Separador;
    private javax.swing.JLabel Subtotal;
    // End of variables declaration//GEN-END:variables
}
