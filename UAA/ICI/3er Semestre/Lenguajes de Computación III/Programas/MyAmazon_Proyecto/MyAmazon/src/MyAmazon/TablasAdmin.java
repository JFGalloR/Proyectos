package MyAmazon;

import MyAmazon.Fonts.Fonts;
import MyAmazon.MessageBox.MessageBox;
import java.sql.Connection;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;
import javax.swing.table.DefaultTableModel;
import javax.swing.table.JTableHeader;

public class TablasAdmin extends javax.swing.JPanel {

    Connection conn;
    int opc;

    public TablasAdmin(int opc) {
        this.conn = MyAmazon.conn;
        this.opc = opc;
        initComponents();
        llenarTabla(opc);
        JTableHeader header = Tabla.getTableHeader();
        java.awt.Font headerFont = new Fonts().setFonts(Fonts.EMBER_RG, 0, 16);
        header.setFont(headerFont);
    }

    private void llenarTabla(int opc) {
        DefaultTableModel model;
        switch (opc) {
            case 0:
                Tabla.setModel(new javax.swing.table.DefaultTableModel(
                        new Object[][]{},
                        new String[]{
                            "Clave", "Usuario", "Contraseña"
                        }
                ) {
                    Class[] types = new Class[]{
                        java.lang.Integer.class, java.lang.String.class, java.lang.String.class
                    };
                    boolean[] canEdit = new boolean[]{
                        false, false, false
                    };

                    @Override
                    public Class getColumnClass(int columnIndex) {
                        return types[columnIndex];
                    }

                    @Override
                    public boolean isCellEditable(int rowIndex, int columnIndex) {
                        return canEdit[columnIndex];
                    }
                });
                model = (DefaultTableModel) Tabla.getModel();
                try {
                    Statement stmt = conn.createStatement();
                    ResultSet resultSet = stmt.executeQuery(
                            "SELECT * FROM " + MyAmazon.clientes + ";");

                    if (resultSet.next()) {
                        do {
                            int d1 = resultSet.getInt("clave");
                            String d2 = resultSet.getString("usuario");
                            String d3 = resultSet.getString("contraseña");
                            model.addRow(new Object[]{d1, d2, d3});
                        } while (resultSet.next());
                    } else {
                        Clave.setEnabled(false);
                        Btn.setEnabled(false);
                        javax.swing.SwingUtilities.invokeLater(() -> {
                            MessageBox.showMB("Administrador de My Amazon", "No hay elementos.", MessageBox.ICON_INFO);
                        });
                    }
                } catch (SQLException ex) {
                    MessageBox.showMB("No se pudo acceder.", "No se pudo acceder a la base de datos.", MessageBox.ICON_ERROR);
                }
                break;
            case 1:
                Tabla.setModel(new javax.swing.table.DefaultTableModel(
                        new Object[][]{},
                        new String[]{
                            "Clave carrito", "Clave usuario", "Clave producto", "Cantidad"
                        }
                ) {
                    Class[] types = new Class[]{
                        java.lang.Integer.class, java.lang.Integer.class, java.lang.Integer.class, java.lang.Integer.class
                    };
                    boolean[] canEdit = new boolean[]{
                        false, false, false, false
                    };

                    @Override
                    public Class getColumnClass(int columnIndex) {
                        return types[columnIndex];
                    }

                    @Override
                    public boolean isCellEditable(int rowIndex, int columnIndex) {
                        return canEdit[columnIndex];
                    }
                });
                model = (DefaultTableModel) Tabla.getModel();
                try {
                    Statement stmt = conn.createStatement();
                    ResultSet resultSet = stmt.executeQuery(
                            "SELECT * FROM " + MyAmazon.carrito + ";");

                    if (resultSet.next()) {
                        do {
                            int d1 = resultSet.getInt("clave_carrito");
                            int d2 = resultSet.getInt("clave_usuario");
                            int d3 = resultSet.getInt("clave_producto");
                            int d4 = resultSet.getInt("cantidad");
                            model.addRow(new Object[]{d1, d2, d3, d4});
                        } while (resultSet.next());
                    } else {
                        Clave.setEnabled(false);
                        Btn.setEnabled(false);
                        javax.swing.SwingUtilities.invokeLater(() -> {
                            MessageBox.showMB("Administrador de My Amazon", "No hay elementos.", MessageBox.ICON_INFO);
                        });
                    }
                } catch (SQLException ex) {
                    MessageBox.showMB("No se pudo acceder.", "No se pudo acceder a la base de datos.", MessageBox.ICON_ERROR);
                }
                break;
            case 3:
                Tabla.setModel(new javax.swing.table.DefaultTableModel(
                        new Object[][]{},
                        new String[]{
                            "Clave mov.", "Clave user.", "Clave prod.", "Cant.", "Precio", "Dir.", "F. y H."
                        }
                ) {
                    Class[] types = new Class[]{
                        java.lang.Integer.class, java.lang.Integer.class, java.lang.Integer.class,
                        java.lang.Integer.class, java.lang.Float.class, java.lang.String.class, java.lang.String.class
                    };
                    boolean[] canEdit = new boolean[]{
                        false, false, false, false, false, false, false
                    };

                    @Override
                    public Class getColumnClass(int columnIndex) {
                        return types[columnIndex];
                    }

                    @Override
                    public boolean isCellEditable(int rowIndex, int columnIndex) {
                        return canEdit[columnIndex];
                    }
                });
                model = (DefaultTableModel) Tabla.getModel();
                try {
                    Statement stmt = conn.createStatement();
                    ResultSet resultSet = stmt.executeQuery(
                            "SELECT * FROM " + MyAmazon.movimientos + ";");

                    if (resultSet.next()) {
                        do {
                            int d1 = resultSet.getInt("clave_movimiento");
                            int d2 = resultSet.getInt("clave_usuario");
                            int d3 = resultSet.getInt("clave_producto");
                            int d4 = resultSet.getInt("cantidad");
                            float d5 = resultSet.getInt("precio");
                            String d6 = resultSet.getString("direccion");
                            String d7 = resultSet.getString("fecha_hora");
                            model.addRow(new Object[]{d1, d2, d3, d4, d5, d6, d7});
                        } while (resultSet.next());
                    } else {
                        Clave.setEnabled(false);
                        Btn.setEnabled(false);
                        javax.swing.SwingUtilities.invokeLater(() -> {
                            MessageBox.showMB("Administrador de My Amazon", "No hay elementos.", MessageBox.ICON_INFO);
                        });
                    }
                } catch (SQLException ex) {
                    MessageBox.showMB("No se pudo acceder.", "No se pudo acceder a la base de datos.", MessageBox.ICON_ERROR);
                }
                break;
        }
    }

    @SuppressWarnings("unchecked")
    // <editor-fold defaultstate="collapsed" desc="Generated Code">//GEN-BEGIN:initComponents
    private void initComponents() {

        Label1 = new javax.swing.JLabel();
        Label2 = new javax.swing.JLabel();
        ScrollPane = new javax.swing.JScrollPane();
        Tabla = new javax.swing.JTable();
        Clave = new javax.swing.JTextField();
        Btn = new javax.swing.JLabel();

        setBackground(new java.awt.Color(255, 255, 255));
        setLayout(null);

        Label1.setFont(new Fonts().setFonts(Fonts.EMBER_RG, 0, 16));
        Label1.setText("Eliminar elemento:");
        add(Label1);
        Label1.setBounds(10, 20, 150, 30);

        Label2.setFont(new Fonts().setFonts(Fonts.EMBER_LT, 0, 14));
        Label2.setText("Ingresa clave:");
        add(Label2);
        Label2.setBounds(10, 60, 140, 20);

        Tabla.setFont(new Fonts().setFonts(Fonts.EMBER_LT, 0, 16));
        Tabla.setSelectionBackground(new java.awt.Color(204, 204, 204));
        Tabla.setSelectionForeground(new java.awt.Color(51, 51, 51));
        Tabla.setShowGrid(false);
        ScrollPane.setViewportView(Tabla);

        add(ScrollPane);
        ScrollPane.setBounds(180, 22, 620, 390);

        Clave.setFont(new Fonts().setFonts(Fonts.EMBER_LT, 0, 14));
        Clave.addKeyListener(new java.awt.event.KeyAdapter() {
            public void keyTyped(java.awt.event.KeyEvent evt) {
                ClaveKeyTyped(evt);
            }
        });
        add(Clave);
        Clave.setBounds(10, 90, 150, 30);

        Btn.setHorizontalAlignment(javax.swing.SwingConstants.CENTER);
        Btn.setIcon(new javax.swing.ImageIcon(getClass().getResource("/MyAmazon/Images/ButtonsAdmin/BtnElim.png"))); // NOI18N
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
        Btn.setBounds(30, 140, 110, 30);
    }// </editor-fold>//GEN-END:initComponents

    private void BtnMouseExited(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_BtnMouseExited
        if(Btn.isEnabled())    
            Btn.setIcon(new javax.swing.ImageIcon(getClass().getResource("/MyAmazon/Images/ButtonsAdmin/BtnElim.png")));
    }//GEN-LAST:event_BtnMouseExited

    private void BtnMouseMoved(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_BtnMouseMoved
        if(Btn.isEnabled())
            Btn.setIcon(new javax.swing.ImageIcon(getClass().getResource("/MyAmazon/Images/ButtonsAdmin/BtnElim_H.png")));
    }//GEN-LAST:event_BtnMouseMoved

    private void BtnMouseClicked(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_BtnMouseClicked
        if (!Clave.getText().isBlank()) {
            String tabla = null;
            String col = null;
            switch (opc) {
                case 0:
                    tabla = MyAmazon.clientes;
                    col = "clave";
                    break;
                case 1:
                    tabla = MyAmazon.carrito;
                    col = "clave_carrito";
                    break;
                case 3:
                    tabla = MyAmazon.movimientos;
                    col = "clave_movimiento";
                    break;
            }
            try {
                Statement stmt = conn.createStatement();
                ResultSet resultSet = stmt.executeQuery(
                        "SELECT * FROM " + tabla + " WHERE " + col + " = " + Clave.getText() + ";");

                if (resultSet.next()) {
                    stmt.executeUpdate(
                            "DELETE FROM " + tabla + " WHERE " + col + " = " + Clave.getText() + ";");
                    Clave.setText("");
                    System.out.println("   -- Elemento eliminado.");
                    MessageBox.showMB("Eliminar elemento.", "Se eliminó el elemento.", MessageBox.ICON_CHECKMARK);
                    llenarTabla(opc);
                } else {
                    MessageBox.showMB("Eliminar elemento.", "No se encontró un elemento con esa clave.", MessageBox.ICON_ERROR);
                }
            } catch (SQLException ex) {
                MessageBox.showMB("No se pudo acceder.", "No se pudo acceder a la base de datos.", MessageBox.ICON_ERROR);
            }
        } else {
            MessageBox.showMB("Eliminar elemento.", "Ingresa la clave del elemento a eliminar.", MessageBox.ICON_WARNIGN);
        }
    }//GEN-LAST:event_BtnMouseClicked

    private void ClaveKeyTyped(java.awt.event.KeyEvent evt) {//GEN-FIRST:event_ClaveKeyTyped
        char caracter = evt.getKeyChar();
        if (!Character.isDigit(caracter)) {
            evt.consume();
        }
    }//GEN-LAST:event_ClaveKeyTyped


    // Variables declaration - do not modify//GEN-BEGIN:variables
    private javax.swing.JLabel Btn;
    private javax.swing.JTextField Clave;
    private javax.swing.JLabel Label1;
    private javax.swing.JLabel Label2;
    private javax.swing.JScrollPane ScrollPane;
    private javax.swing.JTable Tabla;
    // End of variables declaration//GEN-END:variables
}
