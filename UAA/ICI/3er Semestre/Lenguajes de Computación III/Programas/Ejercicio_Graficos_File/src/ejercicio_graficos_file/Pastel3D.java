package ejercicio_graficos_file;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.StringTokenizer;
import javax.swing.JFrame;

import org.jfree.chart.ChartFactory;
import org.jfree.chart.ChartPanel;
import org.jfree.chart.JFreeChart;
import org.jfree.chart.plot.PiePlot3D;
import org.jfree.data.general.DefaultPieDataset;
import org.jfree.data.general.PieDataset;

public class Pastel3D extends JFrame {

    public Pastel3D(String applicationTitle, String chartTitle) {
        super(applicationTitle);
        // This will create the dataset
        PieDataset dataset = createDataset();
        // based on the dataset we create the chart
        JFreeChart chart = createChart(dataset, chartTitle);
        // we put the chart into a panel
        ChartPanel chartPanel = new ChartPanel(chart);
        // default size
        chartPanel.setPreferredSize(new java.awt.Dimension(800, 580));
        // add it to our application
        setContentPane(chartPanel);
        setLocationRelativeTo(null);
    }

    /**
     * * Creates a sample dataset
     */
    private PieDataset createDataset() {
        DefaultPieDataset result = new DefaultPieDataset();
        
        String line, token1, token2;
        StringTokenizer tokenizer;
        try {
            FileReader file = new FileReader("src/Recursos/data.txt");
            BufferedReader br = new BufferedReader(file);
            
            line = br.readLine();line = br.readLine();
            while (line != null) {
                tokenizer = new StringTokenizer(line, ",");
                token1 = tokenizer.nextToken();
                token2 = tokenizer.nextToken();
                result.setValue(token1, Integer.parseInt(token2));
                line = br.readLine();
            }
            file.close();
        } catch (IOException e) {
            System.out.println("Exception");
        }
        return result;

    }

    /**
     * * Creates a chart
     */
    private JFreeChart createChart(PieDataset dataset, String title) {

        JFreeChart chart = ChartFactory.createPieChart3D(
                title, // chart title
                dataset, // data
                true, // include legend
                true,
                false
        );

        PiePlot3D plot = (PiePlot3D) chart.getPlot();
        plot.setStartAngle(290);
        plot.setForegroundAlpha(0.7f);
        return chart;
    }
}
