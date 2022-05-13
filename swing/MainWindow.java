import javax.swing.*;
import java.awt.event.*;
import java.awt.BorderLayout;

public class MainWindow extends JFrame {
	
	private static final long serialVersionUID = 1L;
	private Client client;
	
	// Declare all buttons and actions needed
	JButton hello, media, group, close;
	Hello1 hello1B;
	Hello2 hello2B;
	HelloAction helloAct;
	MediaAction mediaAct;
	GroupAction groupAct;
	SearchMediaAction searchAct;
	SearchGroupAction searchGroupAct;
	PlayAction playAct;
	HelpAction helpAct;
	CloseAction closeAct;
	
    JLabel label = new JLabel();
    
    // Create menu elements
    JMenu menu = new JMenu("Menu");
    JMenuBar menuBar = new JMenuBar();
    JToolBar toolBar = new JToolBar("ToolBar");
    
    // Create text area and make it scrollable
    JTextArea textArea = new JTextArea(30, 50);
    JScrollPane scrollPane = new JScrollPane(textArea);
    
    // Create a panel for bottom buttons
    JPanel buttonsPanel = new JPanel();
    
    public MainWindow(Client client) {
    	this.client = client;
    	setLayout(new BorderLayout());
    	
    	// Arrange elements in the BorderLayout
    	add(scrollPane, BorderLayout.CENTER);
    	add(buttonsPanel, BorderLayout.SOUTH);
    	
    	// Create all buttons and actions needed
    	hello1B = new Hello1("Button 1");
    	hello2B = new Hello2("Button 2");
    	helloAct = new HelloAction("Say 'Hello'");
    	mediaAct = new MediaAction("Show Media");
    	groupAct = new GroupAction("Show Group");
    	searchAct = new SearchMediaAction("Search Media");
    	searchGroupAct = new SearchGroupAction("Search Group");
    	playAct = new PlayAction("Play Media");
    	helpAct = new HelpAction("Help");
    	closeAct = new CloseAction("Close");
    	
    	// Add needed buttons on the menu
    	menu.add(hello1B);
    	menu.add(hello2B);
    	menu.add(helloAct);
    	menu.add(mediaAct);
    	menu.add(groupAct);
    	menu.add(helpAct);
    	menu.add(closeAct);
    	
    	// Add needed buttons on the toolBar
    	toolBar.add(searchAct);
    	toolBar.add(searchGroupAct);
    	toolBar.add(playAct);
    	toolBar.add(closeAct);
    	
    	// Wrap everything in the MenuBar
    	menuBar.add(menu);
    	menuBar.add(toolBar);
    	setJMenuBar(menuBar);
    	
    	// Create and add buttons on the bottom panel
    	buttonsPanel.add( hello = new JButton("Say 'Hello'") , BorderLayout.SOUTH);
    	buttonsPanel.add( media = new JButton("Show Media") , BorderLayout.SOUTH);
    	buttonsPanel.add( group = new JButton("Show Group") , BorderLayout.SOUTH);
    	buttonsPanel.add( close = new JButton("Close"), BorderLayout.SOUTH);
    	
    	// We replace actionListeners with our new Actions.
    	// Set actions for our buttons
    	hello.setAction(helloAct);
    	media.setAction(mediaAct);
    	group.setAction(groupAct);
        close.setAction(closeAct);
        
//    	addLine1.addActionListener(new addLine1());
//    	addLine2.addActionListener(new addLine2());
        
        setDefaultCloseOperation(EXIT_ON_CLOSE);
        pack();
        setVisible(true);
    }
    
    /**
     * Represents an AbstractAction to say hello to the user.
     *
     */
    class Hello1 extends AbstractAction {
    	private static final long serialVersionUID = 2L;
    	
    	public Hello1(String name) {
    		super(name);
    	}
    	
        public void actionPerformed(ActionEvent e){
        	textArea.append("Hello from button 1!\n");
        }
    }
    
    /**
     * Represents an AbstractAction to say hello to the user.
     *
     */
    class Hello2 extends AbstractAction {
    	private static final long serialVersionUID = 2L;
    	
    	public Hello2(String name) {
    		super(name);
    	}
    	
        public void actionPerformed(ActionEvent e){
        	textArea.append("Hello from button 2!\n");
        }
    }
    
    /**
     * Represents an AbstractAction to say hello to the server.
     * This should print a message on the interface.
     *
     */
    class HelloAction extends AbstractAction {
    	private static final long serialVersionUID = 2L;
    	
    	public HelloAction(String name) {
    		super(name);
    	}
    	
        public void actionPerformed(ActionEvent e){
        	String response = client.send("hello");
        	textArea.append(response + "\n");
        }
    }
    
    /**
     * Represents an AbstractAction to get all MediaObject from the server.
     *
     */
    class MediaAction extends AbstractAction {
    	private static final long serialVersionUID = 3L;
    	
    	public MediaAction(String name) {
    		super(name);
    	}
    	
        public void actionPerformed(ActionEvent e){
        	String response = client.send("media");
        	textArea.append(response + "\n");
        }
    }
    
    /**
     * Represents an AbstractAction to search for a MediaObject from user input.
     *
     */
    class SearchMediaAction extends AbstractAction {
    	private static final long serialVersionUID = 3L;
    	
    	public SearchMediaAction(String name) {
    		super(name);
    	}
    	
        public void actionPerformed(ActionEvent e){
        	String result = (String)JOptionPane.showInputDialog(
                    menuBar,
                    "Get information on an available media", 
                    "Search for a media",            
                    JOptionPane.PLAIN_MESSAGE,
                    null,            
                    null, 
                    "Dog"
                 );
        	if (result != null) {
	        	String response = client.send("media " + result);
	        	textArea.append(response + "\n");
        	};
        }
    }
    
    /**
     * Represents an AbstractAction to get all MediaGroup from the server.
     *
     */
    class GroupAction extends AbstractAction {
    	private static final long serialVersionUID = 4L;
    	
    	public GroupAction(String name) {
    		super(name);
    	}
    	
        public void actionPerformed(ActionEvent e){
        	String response = client.send("group");
        	textArea.append(response + "\n");
        }
    }
    
    /**
     * Represents an AbstractAction to search for a MediaGroup from user input.
     *
     */
    class SearchGroupAction extends AbstractAction {
    	private static final long serialVersionUID = 3L;
    	
    	public SearchGroupAction(String name) {
    		super(name);
    	}
    	
        public void actionPerformed(ActionEvent e){
        	String result = (String)JOptionPane.showInputDialog(
                    menuBar,
                    "Get information on an available group", 
                    "Search Group",            
                    JOptionPane.PLAIN_MESSAGE,
                    null,            
                    null, 
                    "Samples"
                 );
        	if (result != null) {
	        	String response = client.send("group " + result);
	        	textArea.append(response + "\n");
        	};
        }
    }
    
    /**
     * Represents an AbstractAction to play a media on the server from user input.
     *
     */
    class PlayAction extends AbstractAction {
    	private static final long serialVersionUID = 3L;
    	
    	public PlayAction(String name) {
    		super(name);
    	}
    	
        public void actionPerformed(ActionEvent e){
        	String result = (String)JOptionPane.showInputDialog(
                    menuBar,
                    "Play a media on the set-top box", 
                    "Play Media",            
                    JOptionPane.PLAIN_MESSAGE,
                    null,            
                    null, 
                    "Dog"
                 );
        	if (result != null) {
	        	String response = client.send("play " + result);
	        	textArea.append(response + "\n");
        	};
        }
    }
    
    /**
     * Represents an AbstractAction to ask help to the server.
     * This should print a message on the interface.
     *
     */
    class HelpAction extends AbstractAction {
    	private static final long serialVersionUID = 2L;
    	
    	public HelpAction(String name) {
    		super(name);
    	}
    	
        public void actionPerformed(ActionEvent e){
        	String response = client.send("help");
        	textArea.append(response + "\n");
        }
    }
    
    /**
     * Represents an AbstractAction to close the client and disconnect
     * from the server.
     *
     */
    class CloseAction extends AbstractAction {
    	private static final long serialVersionUID = 0L;
    	
    	public CloseAction(String name) {
    		super(name);
    	}
    	
        public void actionPerformed(ActionEvent e){
        	System.exit(0);
        }
    }

//    class addLine1 implements ActionListener {
//        public void actionPerformed(ActionEvent e){
//        	textArea.append("Hello from button 1!\n");
//        }
//    }
//    
//    class addLine2 implements ActionListener {
//        public void actionPerformed(ActionEvent e){
//        	textArea.append("Hello from button 2!\n");
//        }
//    }


}
