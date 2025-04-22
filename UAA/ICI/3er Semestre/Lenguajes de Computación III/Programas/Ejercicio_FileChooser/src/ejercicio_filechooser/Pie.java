
package ejercicio_filechooser;
import java.awt.Dimension;
import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.text.DecimalFormat;
import java.util.StringTokenizer;
import java.util.logging.Level;
import java.util.logging.Logger;

import javax.swing.JPanel;

import org.jfree.chart.ChartFactory;
import org.jfree.chart.ChartPanel;
import org.jfree.chart.JFreeChart;
import org.jfree.chart.labels.PieSectionLabelGenerator;
import org.jfree.chart.labels.StandardPieSectionLabelGenerator;
import org.jfree.chart.plot.PiePlot;
import org.jfree.data.general.DefaultPieDataset;
import org.jfree.data.general.PieDataset;

public class Pie extends JPanel {
    File f1;
    public Pie(File f1) {
        this.f1 = f1;
        PieDataset dataset = createDataset();

        // Create chart
        JFreeChart chart = ChartFactory.createPieChart(
                "Pie Chart Example",
                dataset,
                true,
                true,
                false);

        // Format Label
        PieSectionLabelGenerator labelGenerator = new StandardPieSectionLabelGenerator(
                "Edad {0} : ({2})", new DecimalFormat("0"), new DecimalFormat("0%"));
        ((PiePlot) chart.getPlot()).setLabelGenerator(labelGenerator);

        // Create ChartPanel and add it to this JPanel
        ChartPanel chartPanel = new ChartPanel(chart);
        chartPanel.setPreferredSize(new Dimension(530, 430));
        add(chartPanel);
    }

    private PieDataset createDataset() {
        DefaultPieDataset dataset = new DefaultPieDataset();
        FileReader fr = null;
        int a= 0, b= 0, c= 0, d = 0;
        try {
            fr = new FileReader(f1);
            BufferedReader br = new BufferedReader(fr);
            String s;
            while((s = br.readLine()) != null)
            {
                StringTokenizer st = new StringTokenizer(s, ",");
                int cnt = 0;
                while(st.hasMoreTokens())
                {
                    s = st.nextToken();
                    cnt++;
                    if (cnt == 4) {
                        int age = Integer.parseInt(s);
                        if (age > 1 && age <= 20) {
                            a++;
                        }
                        if (age > 20 && age <= 40) {
                            b++;
                        }
                        if (age > 40 && age <= 60){
                            c++;
                        }
                        if (age > 60 && age <= 80) {
                            d++;
                        }
                    }
                }
            }
            dataset.setValue("1-20", a);
            dataset.setValue("21-40", b);
            dataset.setValue("41-60", c);
            dataset.setValue("61-80", d);
            
        } catch (FileNotFoundException ex) {
            Logger.getLogger(Pie.class.getName()).log(Level.SEVERE, null, ex);
        } catch (IOException ex) {
            Logger.getLogger(Pie.class.getName()).log(Level.SEVERE, null, ex);
        } finally {
            try {
                fr.close();
            } catch (IOException ex) {
                Logger.getLogger(Pie.class.getName()).log(Level.SEVERE, null, ex);
            }
        }
        return dataset;
    }
}
