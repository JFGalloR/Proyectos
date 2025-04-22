package MyAmazon;

import MyAmazon.Fonts.Fonts;
import MyAmazon.MessageBox.MessageBox;
import java.io.File;
import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.nio.file.StandardCopyOption;
import java.sql.Connection;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;
import javax.swing.JFileChooser;
import javax.swing.filechooser.FileNameExtensionFilter;
import javax.swing.table.DefaultTableModel;
import javax.swing.table.JTableHeader;

public class TablaInv extends javax.swing.JPanel {

    Connection conn;
    String selectedFilePath = null;

    public TablaInv() {
        this.conn = MyAmazon.conn;
        initComponents();
        llenarTabla();
        JTableHeader header = Tabla.getTableHeader();
        java.awt.Font headerFont = new Fonts().setFonts(Fonts.EMBER_RG, 0, 16);
        header.setFont(headerFont);
    }

    private void llenarTabla() {
        DefaultTableModel model;
        Tabla.setModel(new javax.swing.table.DefaultTableModel(
                new Object[][]{},
                new String[]{
                    "Clave", "Producto", "Imagen", "Categoría", "Cantidad", "Precio"
                }
        ) {
            Class[] types = new Class[]{
                java.lang.Integer.class, java.lang.String.class, java.lang.String.class,
                java.lang.String.class, java.lang.Integer.class, java.lang.Float.class
            };
            boolean[] canEdit = new boolean[]{
                false, false, false, false, false, false
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
                    "SELECT * FROM " + MyAmazon.inventario + ";");

            if (resultSet.next()) {
                do {
                    int d1 = resultSet.getInt("clave");
                    String d2 = resultSet.getString("producto");
                    String d3 = resultSet.getString("imagen");
                    String d4 = resultSet.getString("categoria");
                    int d5 = resultSet.getInt("cantidad");
                    float d6 = resultSet.getFloat("precio");
                    model.addRow(new Object[]{d1, d2, d3, d4, d5, d6});
                } while (resultSet.next());
            } else {
                Clave.setEnabled(false);
                BtnElim.setEnabled(false);
                javax.swing.SwingUtilities.invokeLater(() -> {
                    MessageBox.showMB("Administrador de My Amazon", "No hay elementos.", MessageBox.ICON_INFO);
                });
            }
        } catch (SQLException ex) {
            MessageBox.showMB("No se pudo acceder.", "No se pudo acceder a la base de datos.", MessageBox.ICON_ERROR);
        }
    }

    private boolean validar() {
        if (Producto.getText().isBlank() && (int) Cantidad.getValue() <= 0 && Precio.getText().isBlank()) {
            MessageBox.showMB("Agregar producto.", "Llena los datos.", MessageBox.ICON_WARNIGN);
            return false;
        } else if (Producto.getText().isBlank()) {
            MessageBox.showMB("Agregar producto.", "Ingresa el nombre.", MessageBox.ICON_WARNIGN);
            return false;
        } else if ((int) Cantidad.getValue() <= 0) {
            MessageBox.showMB("Agregar producto.", "La cantidad no puede ser 0.", MessageBox.ICON_WARNIGN);
            return false;
        } else if (Precio.getText().isBlank()) {
            MessageBox.showMB("Agregar producto.", "Ingresa el precio.", MessageBox.ICON_WARNIGN);
            return false;
        }
        return true;
    }

    @SuppressWarnings("unchecked")
    // <editor-fold defaultstate="collapsed" desc="Generated Code">//GEN-BEGIN:initComponents
    private void initComponents() {

        ScrollPane = new javax.swing.JScrollPane();
        Tabla = new javax.swing.JTable();
        BtnElim = new javax.swing.JLabel();
        Clave = new javax.swing.JTextField();
        Label10 = new javax.swing.JLabel();
        Label9 = new javax.swing.JLabel();
        BtnAgr = new javax.swing.JLabel();
        Precio = new javax.swing.JTextField();
        Label8 = new javax.swing.JLabel();
        Label7 = new javax.swing.JLabel();
        Cantidad = new javax.swing.JSpinner();
        Label6 = new javax.swing.JLabel();
        Categoria = new javax.swing.JComboBox<>();
        Label5 = new javax.swing.JLabel();
        Eliminar = new javax.swing.JButton();
        Label4 = new javax.swing.JLabel();
        Añadir = new javax.swing.JButton();
        Label3 = new javax.swing.JLabel();
        Producto = new javax.swing.JTextField();
        Label2 = new javax.swing.JLabel();
        Label1 = new javax.swing.JLabel();

        setBackground(new java.awt.Color(255, 255, 255));
        setLayout(null);

        Tabla.setFont(new Fonts().setFonts(Fonts.EMBER_LT, 0, 16));
        Tabla.setSelectionBackground(new java.awt.Color(204, 204, 204));
        Tabla.setSelectionForeground(new java.awt.Color(51, 51, 51));
        Tabla.setShowGrid(false);
        ScrollPane.setViewportView(Tabla);

        add(ScrollPane);
        ScrollPane.setBounds(250, 22, 550, 390);

        BtnElim.setHorizontalAlignment(javax.swing.SwingConstants.CENTER);
        BtnElim.setIcon(new javax.swing.ImageIcon(getClass().getResource("/MyAmazon/Images/ButtonsAdmin/BtnElim.png"))); // NOI18N
        BtnElim.setName("BtnElim"); // NOI18N
        BtnElim.addMouseMotionListener(new java.awt.event.MouseMotionAdapter() {
            public void mouseMoved(java.awt.event.MouseEvent evt) {
                BtnMouseMoved(evt);
            }
        });
        BtnElim.addMouseListener(new java.awt.event.MouseAdapter() {
            public void mouseClicked(java.awt.event.MouseEvent evt) {
                BtnElimMouseClicked(evt);
            }
            public void mouseExited(java.awt.event.MouseEvent evt) {
                BtnMouseExited(evt);
            }
        });
        add(BtnElim);
        BtnElim.setBounds(60, 380, 110, 30);

        Clave.setFont(new Fonts().setFonts(Fonts.EMBER_LT, 0, 14));
        Clave.addKeyListener(new java.awt.event.KeyAdapter() {
            public void keyTyped(java.awt.event.KeyEvent evt) {
                ClaveKeyTyped(evt);
            }
        });
        add(Clave);
        Clave.setBounds(40, 340, 150, 30);

        Label10.setFont(new Fonts().setFonts(Fonts.EMBER_LT, 0, 14));
        Label10.setText("Ingresa clave:");
        add(Label10);
        Label10.setBounds(40, 310, 140, 20);

        Label9.setFont(new Fonts().setFonts(Fonts.EMBER_RG, 0, 16));
        Label9.setText("Eliminar elemento:");
        add(Label9);
        Label9.setBounds(10, 280, 150, 30);

        BtnAgr.setHorizontalAlignment(javax.swing.SwingConstants.CENTER);
        BtnAgr.setIcon(new javax.swing.ImageIcon(getClass().getResource("/MyAmazon/Images/ButtonsAdmin/BtnAgr.png"))); // NOI18N
        BtnAgr.setVerticalAlignment(javax.swing.SwingConstants.TOP);
        BtnAgr.setName("BtnAgr"); // NOI18N
        BtnAgr.addMouseMotionListener(new java.awt.event.MouseMotionAdapter() {
            public void mouseMoved(java.awt.event.MouseEvent evt) {
                BtnMouseMoved(evt);
            }
        });
        BtnAgr.addMouseListener(new java.awt.event.MouseAdapter() {
            public void mouseClicked(java.awt.event.MouseEvent evt) {
                BtnAgrMouseClicked(evt);
            }
            public void mouseExited(java.awt.event.MouseEvent evt) {
                BtnMouseExited(evt);
            }
        });
        add(BtnAgr);
        BtnAgr.setBounds(150, 240, 70, 30);

        Precio.setFont(new Fonts().setFonts(Fonts.EMBER_LT, 0, 14));
        add(Precio);
        Precio.setBounds(30, 240, 110, 30);

        Label8.setFont(new Fonts().setFonts(Fonts.EMBER_LT, 0, 14));
        Label8.setHorizontalAlignment(javax.swing.SwingConstants.CENTER);
        Label8.setText("$");
        add(Label8);
        Label8.setBounds(20, 240, 10, 30);

        Label7.setFont(new Fonts().setFonts(Fonts.EMBER_LT, 0, 14));
        Label7.setText("Precio:");
        add(Label7);
        Label7.setBounds(20, 220, 110, 20);

        Cantidad.setFont(new Fonts().setFonts(Fonts.EMBER_LT, 0, 10));
        Cantidad.addChangeListener(new javax.swing.event.ChangeListener() {
            public void stateChanged(javax.swing.event.ChangeEvent evt) {
                CantidadStateChanged(evt);
            }
        });
        add(Cantidad);
        Cantidad.setBounds(150, 190, 64, 22);

        Label6.setFont(new Fonts().setFonts(Fonts.EMBER_LT, 0, 14));
        Label6.setText("Cantidad:");
        add(Label6);
        Label6.setBounds(150, 160, 70, 20);

        Categoria.setFont(new Fonts().setFonts(Fonts.EMBER_LT, 0, 10));
        Categoria.setModel(new javax.swing.DefaultComboBoxModel<>(new String[] { "Electrónicos", "Ropa y Accesorios", "Hogar y Jardín", "Deportes y Aire Libre", "Libros", "Juguetes y Juegos", "Cuidado Personal", "Automotriz", "Herramientas", "Alimentos y Bebidas", "Salud y Hogar", "Música", "Películas y TV", "Videojuegos", "Electrodomésticos", "Arte y Manualidades", "Mascotas" }));
        add(Categoria);
        Categoria.setBounds(20, 190, 120, 22);

        Label5.setFont(new Fonts().setFonts(Fonts.EMBER_LT, 0, 14));
        Label5.setText("Categoría:");
        add(Label5);
        Label5.setBounds(20, 160, 110, 20);

        Eliminar.setFont(new Fonts().setFonts(Fonts.EMBER_LT, 0, 10));
        Eliminar.setText("Eliminar");
        Eliminar.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                EliminarActionPerformed(evt);
            }
        });
        add(Eliminar);
        Eliminar.setBounds(150, 130, 70, 23);

        Label4.setFont(new Fonts().setFonts(Fonts.EMBER_LT, 0, 10));
        Label4.setText("No cargada");
        add(Label4);
        Label4.setBounds(80, 130, 70, 20);

        Añadir.setFont(new Fonts().setFonts(Fonts.EMBER_LT, 0, 10));
        Añadir.setText("Añadir");
        Añadir.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                AñadirActionPerformed(evt);
            }
        });
        add(Añadir);
        Añadir.setBounds(20, 130, 60, 23);

        Label3.setFont(new Fonts().setFonts(Fonts.EMBER_LT, 0, 14));
        Label3.setText("Imagen:");
        add(Label3);
        Label3.setBounds(20, 100, 140, 20);

        Producto.setFont(new Fonts().setFonts(Fonts.EMBER_LT, 0, 14));
        add(Producto);
        Producto.setBounds(20, 70, 200, 30);

        Label2.setFont(new Fonts().setFonts(Fonts.EMBER_LT, 0, 14));
        Label2.setText("Nombre del producto:");
        add(Label2);
        Label2.setBounds(20, 50, 140, 20);

        Label1.setFont(new Fonts().setFonts(Fonts.EMBER_RG, 0, 16));
        Label1.setText("Agregar producto:");
        add(Label1);
        Label1.setBounds(10, 20, 150, 30);
    }// </editor-fold>//GEN-END:initComponents

    private void ClaveKeyTyped(java.awt.event.KeyEvent evt) {//GEN-FIRST:event_ClaveKeyTyped
        char caracter = evt.getKeyChar();
        if (!Character.isDigit(caracter)) {
            evt.consume();
        }
    }//GEN-LAST:event_ClaveKeyTyped

    private void BtnMouseMoved(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_BtnMouseMoved
        javax.swing.JLabel btn = (javax.swing.JLabel) evt.getSource();
        if (btn.isEnabled())
            btn.setIcon(new javax.swing.ImageIcon(getClass().getResource("/MyAmazon/Images/ButtonsAdmin/" + btn.getName() + "_H.png")));
    }//GEN-LAST:event_BtnMouseMoved

    private void BtnElimMouseClicked(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_BtnElimMouseClicked
        if (!Clave.getText().isBlank()) {
            try {
                Statement stmt = conn.createStatement();
                ResultSet resultSet = stmt.executeQuery(
                        "SELECT * FROM " + MyAmazon.inventario + " WHERE clave = " + Clave.getText() + ";");

                if (resultSet.next()) {
                    stmt.executeUpdate(
                            "DELETE FROM " + MyAmazon.inventario + " WHERE clave = " + Clave.getText() + ";");
                    Clave.setText("");
                    System.out.println("   -- Elemento eliminado.");
                    MessageBox.showMB("Eliminar elemento.", "Se eliminó el elemento.", MessageBox.ICON_CHECKMARK);
                    llenarTabla();
                } else {
                    MessageBox.showMB("Eliminar elemento.", "No se encontró un elemento con esa clave.", MessageBox.ICON_ERROR);
                }
            } catch (SQLException ex) {
                MessageBox.showMB("No se pudo acceder.", "No se pudo acceder a la base de datos.", MessageBox.ICON_ERROR);
            }
        } else {
            MessageBox.showMB("Eliminar elemento.", "Ingresa la clave del elemento a eliminar.", MessageBox.ICON_WARNIGN);
        }
    }//GEN-LAST:event_BtnElimMouseClicked

    private void BtnMouseExited(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_BtnMouseExited
        javax.swing.JLabel btn = (javax.swing.JLabel) evt.getSource();
        if (btn.isEnabled())
            btn.setIcon(new javax.swing.ImageIcon(getClass().getResource("/MyAmazon/Images/ButtonsAdmin/" + btn.getName() + ".png")));
    }//GEN-LAST:event_BtnMouseExited

    private void AñadirActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_AñadirActionPerformed
        JFileChooser fileChooser = new JFileChooser();

        fileChooser.setFileFilter(new FileNameExtensionFilter(
                "Archivos de Imagen", "png", "jpg", "jpeg", "gif", "bmp"));

        int result = fileChooser.showOpenDialog(this);
        if (result == JFileChooser.APPROVE_OPTION) {
            File selectedFile = fileChooser.getSelectedFile();
            selectedFilePath = selectedFile.getAbsolutePath();
            Label4.setText("Cargada");
        } else {
            MessageBox.showMB("Agregar imagen.", "Archivo no seleccionado.", MessageBox.ICON_WARNIGN);
        }
    }//GEN-LAST:event_AñadirActionPerformed

    private void BtnAgrMouseClicked(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_BtnAgrMouseClicked
        if (validar()) {
            try {
                float precio = Float.parseFloat(Precio.getText());
                try {
                    Statement stmt = conn.createStatement();
                    if (selectedFilePath != null) {
                        stmt.executeUpdate("INSERT INTO " + MyAmazon.inventario
                                + " (producto, imagen, categoria, cantidad, precio) VALUES ('"
                                + Producto.getText() + "', '" + ("/MyAmazon/Images/Products/" + new File(selectedFilePath).getName()) + "', '" + Categoria.getItemAt(Categoria.getSelectedIndex())
                                + "', " + ((int) Cantidad.getValue()) + ", " + precio + ");");
                        saveImage(selectedFilePath, "src" + File.separator + "MyAmazon" + File.separator + "Images" + File.separator + "Products");
                    } else {
                        stmt.executeUpdate("INSERT INTO " + MyAmazon.inventario
                                + " (producto, categoria, cantidad, precio) VALUES ('"
                                + Producto.getText() + "', '" + Categoria.getItemAt(Categoria.getSelectedIndex())
                                + "', " + ((int) Cantidad.getValue()) + ", " + precio + ");");
                    }
                    Producto.setText("");
                    selectedFilePath = null;
                    Label4.setText("No cargada");
                    Cantidad.setValue(0);
                    Categoria.setSelectedIndex(0);
                    Precio.setText("");
                    System.out.println("   ++ Producto agregado.");
                    MessageBox.showMB("Agregar producto.", "Producto ingresado a inventario.", MessageBox.ICON_CHECKMARK);
                    llenarTabla();
                } catch (SQLException ex) {
                    MessageBox.showMB("No se pudo acceder.", "No se pudo acceder a la base de datos.", MessageBox.ICON_ERROR);
                }
            } catch (NumberFormatException e) {
                MessageBox.showMB("Agregar producto.", "Precio no válido.", MessageBox.ICON_WARNIGN);
            }
        }
    }//GEN-LAST:event_BtnAgrMouseClicked

    private void EliminarActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_EliminarActionPerformed
        selectedFilePath = null;
        Label4.setText("No cargada");
    }//GEN-LAST:event_EliminarActionPerformed

    private void CantidadStateChanged(javax.swing.event.ChangeEvent evt) {//GEN-FIRST:event_CantidadStateChanged
        if ((int) Cantidad.getValue() < 0) {
            Cantidad.setValue(0);
        }
    }//GEN-LAST:event_CantidadStateChanged

    private void saveImage(String sourcePath, String destinationFolder) {
        try {
            File destinationFolderFile = new File(destinationFolder);
            if (!destinationFolderFile.exists()) {
                destinationFolderFile.mkdirs();
            }
            String fileName = new File(sourcePath).getName();
            String destinationPath = destinationFolder + File.separator + fileName;
            Files.copy(Paths.get(sourcePath), Paths.get(destinationPath), StandardCopyOption.REPLACE_EXISTING);
            System.out.println("ss");
        } catch (IOException e) {
            MessageBox.showMB("Agregar imagen.", "No se puedo guardar la imagen.", MessageBox.ICON_ERROR);
        }
    }

    // Variables declaration - do not modify//GEN-BEGIN:variables
    private javax.swing.JButton Añadir;
    private javax.swing.JLabel BtnAgr;
    private javax.swing.JLabel BtnElim;
    private javax.swing.JSpinner Cantidad;
    private javax.swing.JComboBox<String> Categoria;
    private javax.swing.JTextField Clave;
    private javax.swing.JButton Eliminar;
    private javax.swing.JLabel Label1;
    private javax.swing.JLabel Label10;
    private javax.swing.JLabel Label2;
    private javax.swing.JLabel Label3;
    private javax.swing.JLabel Label4;
    private javax.swing.JLabel Label5;
    private javax.swing.JLabel Label6;
    private javax.swing.JLabel Label7;
    private javax.swing.JLabel Label8;
    private javax.swing.JLabel Label9;
    private javax.swing.JTextField Precio;
    private javax.swing.JTextField Producto;
    private javax.swing.JScrollPane ScrollPane;
    private javax.swing.JTable Tabla;
    // End of variables declaration//GEN-END:variables
}
