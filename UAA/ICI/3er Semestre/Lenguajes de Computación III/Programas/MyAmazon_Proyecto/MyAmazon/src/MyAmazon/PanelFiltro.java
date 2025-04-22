package MyAmazon;

import MyAmazon.Fonts.Fonts;
import MyAmazon.MessageBox.MessageBox;
import java.sql.Connection;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;
import java.text.ParseException;

public class PanelFiltro extends javax.swing.JPanel {

    Connection conn;
    Compras p;
    String ord = "";
    String cat = "";
    String prc = "";

    public PanelFiltro(Compras p) {
        initComponents();
        this.p = p;
        this.conn = MyAmazon.conn;
        agregarCombobox();
    }

    void agregarCombobox() {
        try {
            Statement stmt = conn.createStatement();
            ResultSet resultSet = stmt.executeQuery(
                    "SELECT DISTINCT categoria FROM " + MyAmazon.inventario + ";");

            if (resultSet.next()) {
                do {
                    String cat = resultSet.getString("categoria");
                    Categoria.addItem(cat);
                } while (resultSet.next());
            }
        } catch (SQLException ex) {
            MessageBox.showMB("No se pudo acceder.", "No se pudo acceder a la base de datos.", MessageBox.ICON_ERROR);
        }
    }

    @SuppressWarnings("unchecked")
    // <editor-fold defaultstate="collapsed" desc="Generated Code">//GEN-BEGIN:initComponents
    private void initComponents() {

        Precio = new javax.swing.JCheckBox();
        Btn = new javax.swing.JButton();
        Max = new javax.swing.JSpinner();
        Min = new javax.swing.JSpinner();
        Label4 = new javax.swing.JLabel();
        Categoria = new javax.swing.JComboBox<>();
        Label3 = new javax.swing.JLabel();
        Ordenar = new javax.swing.JComboBox<>();
        Label2 = new javax.swing.JLabel();
        Label1 = new javax.swing.JLabel();
        Backgorund = new javax.swing.JLabel();

        setBackground(new java.awt.Color(255, 255, 255));
        setPreferredSize(new java.awt.Dimension(1150, 82));
        setLayout(null);

        Precio.setFont(new Fonts().setFonts(Fonts.EMBER_LT, 0, 10));
        Precio.setText("Filtrar por precio");
        Precio.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                PrecioActionPerformed(evt);
            }
        });
        add(Precio);
        Precio.setBounds(620, 20, 110, 20);

        Btn.setFont(new Fonts().setFonts(Fonts.EMBER_LT, 0, 10));
        Btn.setText("Filtrar");
        Btn.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                BtnActionPerformed(evt);
            }
        });
        add(Btn);
        Btn.setBounds(730, 20, 60, 20);

        Max.setFont(new Fonts().setFonts(Fonts.EMBER_LT, 0, 10));
        Max.setEnabled(false);
        Max.setFocusable(false);
        Max.setRequestFocusEnabled(false);
        Max.addChangeListener(new javax.swing.event.ChangeListener() {
            public void stateChanged(javax.swing.event.ChangeEvent evt) {
                MaxStateChanged(evt);
            }
        });
        add(Max);
        Max.setBounds(530, 20, 80, 22);

        Min.setFont(new Fonts().setFonts(Fonts.EMBER_LT, 0, 10));
        Min.setEnabled(false);
        Min.setFocusable(false);
        Min.setRequestFocusEnabled(false);
        Min.addChangeListener(new javax.swing.event.ChangeListener() {
            public void stateChanged(javax.swing.event.ChangeEvent evt) {
                MinStateChanged(evt);
            }
        });
        add(Min);
        Min.setBounds(440, 20, 80, 22);

        Label4.setFont(new Fonts().setFonts(Fonts.EMBER_RG, 0, 10));
        Label4.setText("$");
        add(Label4);
        Label4.setBounds(430, 20, 10, 16);

        Categoria.setFont(new Fonts().setFonts(Fonts.EMBER_LT, 0, 10));
        Categoria.setModel(new javax.swing.DefaultComboBoxModel<>(new String[] { "Todas" }));
        Categoria.setBorder(null);
        Categoria.setFocusable(false);
        Categoria.setRequestFocusEnabled(false);
        Categoria.setVerifyInputWhenFocusTarget(false);
        Categoria.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                CategoriaActionPerformed(evt);
            }
        });
        add(Categoria);
        Categoria.setBounds(260, 20, 140, 20);

        Label3.setFont(new Fonts().setFonts(Fonts.EMBER_RG, 0, 10));
        Label3.setHorizontalAlignment(javax.swing.SwingConstants.LEFT);
        Label3.setText("  Desde (mín) a (máx):");
        add(Label3);
        Label3.setBounds(440, 0, 140, 16);

        Ordenar.setFont(new Fonts().setFonts(Fonts.EMBER_LT, 0, 10));
        Ordenar.setModel(new javax.swing.DefaultComboBoxModel<>(new String[] { "Por Defecto", "Alfabético (A-Z)", "Alfabético (Z-A)", "Precio (mayor a menor)", "Precio (menor a mayor)" }));
        Ordenar.setBorder(null);
        Ordenar.setFocusable(false);
        Ordenar.setRequestFocusEnabled(false);
        Ordenar.setVerifyInputWhenFocusTarget(false);
        Ordenar.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                OrdenarActionPerformed(evt);
            }
        });
        add(Ordenar);
        Ordenar.setBounds(100, 20, 140, 20);

        Label2.setFont(new Fonts().setFonts(Fonts.EMBER_RG, 0, 10));
        Label2.setText("  Categoría:");
        add(Label2);
        Label2.setBounds(260, 0, 140, 16);

        Label1.setFont(new Fonts().setFonts(Fonts.EMBER_RG, 0, 10));
        Label1.setText("  Ordenar por:");
        add(Label1);
        Label1.setBounds(100, 0, 140, 16);

        Backgorund.setBackground(new java.awt.Color(255, 255, 255));
        Backgorund.setIcon(new javax.swing.ImageIcon(getClass().getResource("/MyAmazon/Images/PanelFiltro.png"))); // NOI18N
        add(Backgorund);
        Backgorund.setBounds(0, 0, 1140, 80);
    }// </editor-fold>//GEN-END:initComponents

    private void MinStateChanged(javax.swing.event.ChangeEvent evt) {//GEN-FIRST:event_MinStateChanged
        if ((int) Min.getValue() < 0) {
            Min.setValue(0);
        } else if ((int) Min.getValue() > (int) Max.getValue()) {
            Min.setValue(Max.getValue());
        }
        prc = "precio BETWEEN " + (int) Min.getValue() + " AND " + (int) Max.getValue();
    }//GEN-LAST:event_MinStateChanged

    private void MaxStateChanged(javax.swing.event.ChangeEvent evt) {//GEN-FIRST:event_MaxStateChanged
        if ((int) Max.getValue() < 0) {
            Max.setValue(0);
        } else if ((int) Min.getValue() > (int) Max.getValue()) {
            Max.setValue(Min.getValue());
        }
        prc = "precio BETWEEN " + (int) Min.getValue() + " AND " + (int) Max.getValue();
    }//GEN-LAST:event_MaxStateChanged

    private void BtnActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_BtnActionPerformed
        try {
            Max.commitEdit();
            Min.commitEdit();
            if ((int) Max.getValue() == 0 && Max.isEnabled()) {
                MessageBox.showMB("Filtrar productos.", "Ingresa una cantidad máxima.", MessageBox.ICON_WARNIGN);
            } else {
                if (p.bus.isBlank()) {
                    if (cat.isBlank() && prc.isBlank()) {
                        p.agregarProductos(ord);
                    } else if (prc.isBlank()) {
                        p.agregarProductos("WHERE " + cat + ord);
                    } else if (cat.isBlank()) {
                        p.agregarProductos("WHERE " + prc + ord);
                    } else {
                        p.agregarProductos("WHERE " + cat + " AND " + prc + ord);
                    }
                } else {
                    if (cat.isBlank() && prc.isBlank()) {
                        p.agregarProductos(ord);
                    } else if (prc.isBlank()) {
                        p.agregarProductos(" AND " + cat + ord);
                    } else if (cat.isBlank()) {
                        p.agregarProductos(" AND " + prc + ord);
                    } else {
                        p.agregarProductos(" AND " + cat + " AND " + prc + ord);
                    }
                }
            }
        } catch (ParseException ex) {
            MessageBox.showMB("Filtrar productos.", "Ingresa una cantidad válida.", MessageBox.ICON_WARNIGN);
        }
    }//GEN-LAST:event_BtnActionPerformed

    private void PrecioActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_PrecioActionPerformed
        if (Precio.isSelected()) {
            Max.setEnabled(true);
            Min.setEnabled(true);
            prc = "precio BETWEEN " + (int) Min.getValue() + " AND " + (int) Max.getValue();
        } else {
            Max.setEnabled(false);
            Min.setEnabled(false);
            prc = "";
        }
    }//GEN-LAST:event_PrecioActionPerformed

    private void OrdenarActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_OrdenarActionPerformed
        switch (Ordenar.getSelectedIndex()) {
            case 0:
                ord = "";
                break;
            case 1:
                ord = " ORDER BY producto ASC";
                break;
            case 2:
                ord = " ORDER BY producto DESC";
                break;
            case 3:
                ord = " ORDER BY precio DESC";
                break;
            case 4:
                ord = " ORDER BY precio ASC";
                break;
        }
    }//GEN-LAST:event_OrdenarActionPerformed

    private void CategoriaActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_CategoriaActionPerformed
        if (Categoria.getSelectedIndex() == 0) {
            cat = "";
        } else {
            cat = "categoria = '" + Categoria.getSelectedItem().toString() + "'";
        }
    }//GEN-LAST:event_CategoriaActionPerformed


    // Variables declaration - do not modify//GEN-BEGIN:variables
    private javax.swing.JLabel Backgorund;
    private javax.swing.JButton Btn;
    private javax.swing.JComboBox<String> Categoria;
    private javax.swing.JLabel Label1;
    private javax.swing.JLabel Label2;
    private javax.swing.JLabel Label3;
    private javax.swing.JLabel Label4;
    private javax.swing.JSpinner Max;
    private javax.swing.JSpinner Min;
    private javax.swing.JComboBox<String> Ordenar;
    private javax.swing.JCheckBox Precio;
    // End of variables declaration//GEN-END:variables
}
