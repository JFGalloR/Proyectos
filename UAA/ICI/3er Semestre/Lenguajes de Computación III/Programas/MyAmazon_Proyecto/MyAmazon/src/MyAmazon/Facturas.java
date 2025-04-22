package MyAmazon;

import MyAmazon.Fonts.Fonts;
import MyAmazon.MessageBox.MessageBox;
import java.sql.Connection;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;

public class Facturas extends javax.swing.JPanel {

    Connection conn;
    int clave;

    public Facturas() {
        this.conn = MyAmazon.conn;
        this.clave = Compras.clave;
        initComponents();
        verificarFacturas();
    }

    private void verificarFacturas() {
        try {
            Statement stmt = conn.createStatement();
            ResultSet resultSet1 = stmt.executeQuery(
                    "SELECT * FROM " + MyAmazon.movimientos + " WHERE clave_usuario = " + clave + ";");

            if (!resultSet1.next()) {
                javax.swing.JLabel l = new javax.swing.JLabel("- Realiza compras en My Amazon -");
                l.setHorizontalAlignment(javax.swing.JLabel.CENTER);
                l.setPreferredSize(new java.awt.Dimension(300, 100));
                l.setFont(new Fonts().setFonts(Fonts.EMBER_LT, 0, 20));
                Productos.add(l);
                Productos.revalidate();
                Productos.repaint();
                Contenedor.setVisible(false);
                javax.swing.SwingUtilities.invokeLater(() -> {
                    MessageBox.showMB("Mis Facturas", "No hay compras realizadas.", MessageBox.ICON_INFO);;
                });
            } else {

                agregarComboBox();
            }
        } catch (SQLException ex) {
            MessageBox.showMB("No se pudo acceder.", "No se pudo acceder a la base de datos.", MessageBox.ICON_ERROR);
        }
    }

    private void agregarProductos(String f_h) {
        try {
            Statement stmt = conn.createStatement();
            ResultSet resultSet1 = stmt.executeQuery(
                    "SELECT * FROM " + MyAmazon.movimientos + " WHERE clave_usuario = " + clave + " AND fecha_hora = '" + f_h + "';");
            Productos.setPreferredSize(new java.awt.Dimension(500, 50));
            Productos.removeAll();

            if (resultSet1.next()) {
                float total = 0;
                int c = 0;
                int aux = Productos.getPreferredSize().width;

                ScrollPane.getVerticalScrollBar().setUnitIncrement(10);
                Direccion.setText(resultSet1.getString("Direccion"));

                do {
                    String prod = resultSet1.getString("producto");
                    int cant = resultSet1.getInt("cantidad");
                    float precio = resultSet1.getFloat("precio");
                    total += precio * cant;
                    c++;

                    ProductoFactura p = new ProductoFactura(prod, cant, precio);
                    
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
            }
        } catch (SQLException ex) {
            MessageBox.showMB("No se pudo acceder.", "No se pudo acceder a la base de datos.", MessageBox.ICON_ERROR);
        }
    }

    private void agregarComboBox() {
        try {
            Statement stmt = conn.createStatement();
            ResultSet resultSet = stmt.executeQuery(
                    "SELECT DISTINCT fecha_hora FROM " + MyAmazon.movimientos + " WHERE clave_usuario = " + clave + ";");

            if (resultSet.next()) {

                do {
                    String cat = resultSet.getString("fecha_hora");
                    FechaHora.addItem(cat);
                } while (resultSet.next());
            }
        } catch (SQLException ex) {
            MessageBox.showMB("No se pudo acceder.", "No se pudo acceder a la base de datos.", MessageBox.ICON_ERROR);
        }
    }

    @SuppressWarnings("unchecked")
    // <editor-fold defaultstate="collapsed" desc="Generated Code">//GEN-BEGIN:initComponents
    private void initComponents() {

        ScrollPane = new javax.swing.JScrollPane();
        Productos = new javax.swing.JPanel();
        Contenedor = new javax.swing.JPanel();
        Separador = new javax.swing.JSeparator();
        Subtotal = new javax.swing.JLabel();
        Label4 = new javax.swing.JLabel();
        CantProd = new javax.swing.JLabel();
        Label3 = new javax.swing.JLabel();
        Direccion = new javax.swing.JTextArea();
        Label2 = new javax.swing.JLabel();
        FechaHora = new javax.swing.JComboBox<>();
        Label1 = new javax.swing.JLabel();

        setBackground(new java.awt.Color(255, 255, 255));
        setLayout(null);

        ScrollPane.setBorder(null);
        ScrollPane.setHorizontalScrollBarPolicy(javax.swing.ScrollPaneConstants.HORIZONTAL_SCROLLBAR_NEVER);
        ScrollPane.setPreferredSize(new java.awt.Dimension(520, 60));

        Productos.setBackground(new java.awt.Color(255, 255, 255));
        Productos.setPreferredSize(new java.awt.Dimension(500, 50));
        ScrollPane.setViewportView(Productos);

        add(ScrollPane);
        ScrollPane.setBounds(20, 20, 520, 420);

        Contenedor.setBackground(new java.awt.Color(255, 255, 255));
        Contenedor.setLayout(null);
        Contenedor.add(Separador);
        Separador.setBounds(10, 390, 210, 10);

        Subtotal.setFont(new Fonts().setFonts(Fonts.EMBER_HE, 0, 22));
        Subtotal.setVerticalAlignment(javax.swing.SwingConstants.BOTTOM);
        Contenedor.add(Subtotal);
        Subtotal.setBounds(90, 350, 130, 30);

        Label4.setFont(new Fonts().setFonts(Fonts.EMBER_RG, 0, 16));
        Label4.setForeground(new java.awt.Color(102, 102, 102));
        Label4.setText("Subtotal:");
        Label4.setVerticalAlignment(javax.swing.SwingConstants.BOTTOM);
        Contenedor.add(Label4);
        Label4.setBounds(20, 350, 70, 30);

        CantProd.setFont(new Fonts().setFonts(Fonts.EMBER_LT, 0, 14));
        CantProd.setVerticalAlignment(javax.swing.SwingConstants.BOTTOM);
        Contenedor.add(CantProd);
        CantProd.setBounds(100, 320, 90, 30);

        Label3.setFont(new Fonts().setFonts(Fonts.EMBER_RG, 0, 14));
        Label3.setForeground(new java.awt.Color(102, 102, 102));
        Label3.setText("Cant. Prod:");
        Label3.setVerticalAlignment(javax.swing.SwingConstants.BOTTOM);
        Contenedor.add(Label3);
        Label3.setBounds(20, 320, 70, 30);

        Direccion.setEditable(false);
        Direccion.setBackground(new java.awt.Color(255, 255, 255));
        Direccion.setColumns(20);
        Direccion.setFont(new Fonts().setFonts(Fonts.EMBER_LT, 0, 14));
        Direccion.setLineWrap(true);
        Direccion.setRows(5);
        Direccion.setWrapStyleWord(true);
        Direccion.setBorder(null);
        Direccion.setFocusable(false);
        Direccion.setRequestFocusEnabled(false);
        Contenedor.add(Direccion);
        Direccion.setBounds(20, 120, 190, 100);

        Label2.setFont(new Fonts().setFonts(Fonts.EMBER_RG, 0, 16));
        Label2.setForeground(new java.awt.Color(102, 102, 102));
        Label2.setText("Dirección:");
        Label2.setVerticalAlignment(javax.swing.SwingConstants.BOTTOM);
        Contenedor.add(Label2);
        Label2.setBounds(20, 80, 70, 30);

        FechaHora.setFont(new Fonts().setFonts(Fonts.EMBER_LT, 0, 12));
        FechaHora.setFocusable(false);
        FechaHora.setRequestFocusEnabled(false);
        FechaHora.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                FechaHoraActionPerformed(evt);
            }
        });
        Contenedor.add(FechaHora);
        FechaHora.setBounds(40, 50, 150, 22);

        Label1.setFont(new Fonts().setFonts(Fonts.EMBER_RG, 0, 22));
        Label1.setForeground(new java.awt.Color(102, 102, 102));
        Label1.setText("Fecha de Factura:");
        Contenedor.add(Label1);
        Label1.setBounds(20, 0, 190, 30);

        add(Contenedor);
        Contenedor.setBounds(540, 20, 230, 420);
    }// </editor-fold>//GEN-END:initComponents

    private void FechaHoraActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_FechaHoraActionPerformed
        agregarProductos(FechaHora.getItemAt(FechaHora.getSelectedIndex()));
    }//GEN-LAST:event_FechaHoraActionPerformed


    // Variables declaration - do not modify//GEN-BEGIN:variables
    private javax.swing.JLabel CantProd;
    private javax.swing.JPanel Contenedor;
    private javax.swing.JTextArea Direccion;
    private javax.swing.JComboBox<String> FechaHora;
    private javax.swing.JLabel Label1;
    private javax.swing.JLabel Label2;
    private javax.swing.JLabel Label3;
    private javax.swing.JLabel Label4;
    private javax.swing.JPanel Productos;
    public javax.swing.JScrollPane ScrollPane;
    private javax.swing.JSeparator Separador;
    private javax.swing.JLabel Subtotal;
    // End of variables declaration//GEN-END:variables
}
