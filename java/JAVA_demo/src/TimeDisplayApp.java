//import javax.swing.*;
//import java.awt.*;
//import java.text.SimpleDateFormat;
//import java.util.Date;
//
//public class TimeDisplayApp extends JFrame {
//
//    private JLabel timeLabel;
//
//    public TimeDisplayApp() {
//        // 设置窗口标题
//        setTitle("Time Display App");
//
//        // 创建时间显示标签
//        timeLabel = new JLabel();
//        timeLabel.setFont(new Font("Arial", Font.BOLD, 24));
//        timeLabel.setHorizontalAlignment(SwingConstants.CENTER);
//
//        // 将时间显示标签添加到窗口中
//        add(timeLabel);
//
//        // 设置窗口大小和居中显示
//        setSize(300, 200);
//        setLocationRelativeTo(null);
//
//        // 设置窗口关闭时的操作
//        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
//
//        // 创建并启动时间显示线程
//        TimeDisplayThread timeDisplayThread = new TimeDisplayThread();
//        timeDisplayThread.start();
//    }
//
//    private class TimeDisplayThread extends Thread {
//        @Override
//        public void run() {
//            try {
//                while (true) {
//                    // 获取当前时间
//                    Date now = new Date();
//                    SimpleDateFormat sdf = new SimpleDateFormat("HH:mm:ss");
//                    String time = sdf.format(now);
//
//                    // 更新时间显示标签
//                    timeLabel.setText(time);
//
//                    // 休眠1秒
//                    Thread.sleep(1000);
//                }
//            } catch (InterruptedException e) {
//                e.printStackTrace();
//            }
//        }
//    }
//
//    public static void main(String[] args) {
//        SwingUtilities.invokeLater(() -> {
//            TimeDisplayApp app = new TimeDisplayApp();
//            app.setVisible(true);
//        });
//    }
//}


import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.text.SimpleDateFormat;
import java.util.Date;

public class TimeDisplayApp extends JFrame {

    private JLabel timeLabel;
    private JButton startButton;
    private JTextField progressTextField;

    public TimeDisplayApp() {
        // 设置窗口标题
        setTitle("Time Display App");

        // 创建时间显示标签
        timeLabel = new JLabel();
        timeLabel.setFont(new Font("Arial", Font.BOLD, 24));
        timeLabel.setHorizontalAlignment(SwingConstants.CENTER);

        // 创建开始按钮
        startButton = new JButton("Start Task");

        // 创建进度文本框
        progressTextField = new JTextField();
        progressTextField.setEditable(false);

        // 创建主面板，并设置布局
        JPanel mainPanel = new JPanel(new BorderLayout());
        mainPanel.add(timeLabel, BorderLayout.NORTH);
        mainPanel.add(startButton, BorderLayout.CENTER);
        mainPanel.add(progressTextField, BorderLayout.SOUTH);

        // 将主面板添加到窗口中
        add(mainPanel);

        // 设置窗口大小和居中显示
        setSize(300, 200);
        setLocationRelativeTo(null);

        // 设置窗口关闭时的操作
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        // 注册开始按钮的点击事件监听器
        startButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                startButton.setEnabled(false); // 禁用开始按钮
                progressTextField.setText(""); // 清空进度文本框

                // 创建并启动耗时任务线程
                TaskThread taskThread = new TaskThread();
                taskThread.start();
            }
        });

        // 创建并启动时间显示线程
        TimeDisplayThread timeDisplayThread = new TimeDisplayThread();
        timeDisplayThread.start();
    }

    private class TimeDisplayThread extends Thread {
        @Override
        public void run() {
            try {
                while (true) {
                    // 获取当前时间
                    Date now = new Date();
                    SimpleDateFormat sdf = new SimpleDateFormat("HH:mm:ss");
                    String time = sdf.format(now);

                    // 更新时间显示标签
                    timeLabel.setText("Current Time: " + time);

                    // 休眠1秒
                    Thread.sleep(1000);
                }
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
    }

    private class TaskThread extends Thread {
        @Override
        public void run() {
            try {
                for (int i = 0; i <= 100; i++) {
                    // 模拟耗时任务
                    Thread.sleep(100);

                    // 更新进度文本框
                    final int progress = i;
                    SwingUtilities.invokeLater(new Runnable() {
                        public void run() {
                            progressTextField.setText("Progress: " + progress + "%");
                        }
                    });
                }
            } catch (InterruptedException e) {
                e.printStackTrace();
            } finally {
                // 任务完成后启用开始按钮
                SwingUtilities.invokeLater(new Runnable() {
                    public void run() {
                        startButton.setEnabled(true);
                    }
                });
            }
        }
    }

    public static void main(String[] args) {
        SwingUtilities.invokeLater(() -> {
            TimeDisplayApp app = new TimeDisplayApp();
            app.setVisible(true);
        });
    }
}
