package MyAmazon;

public class IdenReg extends javax.swing.JPanel {
    public IdenReg(boolean tipo) {
        initComponents();
        if(tipo)
        {
            Ingreso ing = new Ingreso();
            ing.setSize(430, 492);
            ing.setLocation(0, 0);
            Subpanel.removeAll();
            Subpanel.add(ing);
            Subpanel.revalidate();
            Subpanel.repaint();
        }
        else
        {
            Registro reg = new Registro();
            reg.setSize(430, 492);
            reg.setLocation(0, 0);
            Subpanel.removeAll();
            Subpanel.add(reg);
            Subpanel.revalidate();
            Subpanel.repaint();
        }
    }

    @SuppressWarnings("unchecked")
    // <editor-fold defaultstate="collapsed" desc="Generated Code">//GEN-BEGIN:initComponents
    private void initComponents() {

        Panel = new javax.swing.JPanel();
        Logo = new javax.swing.JLabel();
        Subpanel = new javax.swing.JPanel();

        setLayout(null);

        Panel.setBackground(new java.awt.Color(255, 255, 255));

        Logo.setHorizontalAlignment(javax.swing.SwingConstants.CENTER);
        Logo.setIcon(new javax.swing.ImageIcon(getClass().getResource("/MyAmazon/Images/LogoN.png"))); // NOI18N
        Logo.addMouseListener(new java.awt.event.MouseAdapter() {
            public void mouseClicked(java.awt.event.MouseEvent evt) {
                LogoMouseClicked(evt);
            }
        });

        Subpanel.setBackground(new java.awt.Color(204, 204, 204));

        javax.swing.GroupLayout SubpanelLayout = new javax.swing.GroupLayout(Subpanel);
        Subpanel.setLayout(SubpanelLayout);
        SubpanelLayout.setHorizontalGroup(
            SubpanelLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGap(0, 430, Short.MAX_VALUE)
        );
        SubpanelLayout.setVerticalGroup(
            SubpanelLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGap(0, 492, Short.MAX_VALUE)
        );

        javax.swing.GroupLayout PanelLayout = new javax.swing.GroupLayout(Panel);
        Panel.setLayout(PanelLayout);
        PanelLayout.setHorizontalGroup(
            PanelLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(PanelLayout.createSequentialGroup()
                .addGroup(PanelLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addGroup(PanelLayout.createSequentialGroup()
                        .addGap(489, 489, 489)
                        .addComponent(Logo))
                    .addGroup(PanelLayout.createSequentialGroup()
                        .addGap(360, 360, 360)
                        .addComponent(Subpanel, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)))
                .addContainerGap(360, Short.MAX_VALUE))
        );
        PanelLayout.setVerticalGroup(
            PanelLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(PanelLayout.createSequentialGroup()
                .addGap(35, 35, 35)
                .addComponent(Logo)
                .addGap(30, 30, 30)
                .addComponent(Subpanel, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE))
        );

        add(Panel);
        Panel.setBounds(0, 0, 1150, 650);
    }// </editor-fold>//GEN-END:initComponents

    private void LogoMouseClicked(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_LogoMouseClicked
        Inicio pI = new Inicio();
        pI.setSize(1150, 648);
        pI.setLocation(0, 0);
        MyAmazon.Panel.removeAll();
        MyAmazon.Panel.add(pI);
        MyAmazon.Panel.revalidate();
        MyAmazon.Panel.repaint();
    }//GEN-LAST:event_LogoMouseClicked


    // Variables declaration - do not modify//GEN-BEGIN:variables
    private javax.swing.JLabel Logo;
    private javax.swing.JPanel Panel;
    private javax.swing.JPanel Subpanel;
    // End of variables declaration//GEN-END:variables
}
