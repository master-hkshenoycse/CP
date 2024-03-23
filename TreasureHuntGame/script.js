document.addEventListener("DOMContentLoaded", function() {


    const gridContainer = document.getElementById('gridContainer');
    const gridSize = 10;
    let grid = [];

    //hunter co ordinates
    let hunter_x=-1,hunter_y=-1;

    //count of treasure still left
    let cnt_5=0,cnt_6=0,cnt_7=0,cnt_8=0;
    
    //keeping track of round number and score 
    let round_number=0,user_score=0;

    //initialize the empty grid
    function initializeGrid() {
        for (let i = 0; i < gridSize; i++) {
            grid[i] = [];
            for (let j = 0; j < gridSize; j++) {
                grid[i][j] = '';
            }
        }
    }

    //render the empty grid for setup stage
    function renderGrid() {
        gridContainer.innerHTML = ''; // Clear previous grid
    
        for (let i = 0; i < 10; i++) {
            const row = document.createElement('div');
            row.classList.add('row'); // Adding a class for styling (optional)
            
            for (let j = 0; j < 10; j++) {
                const cellElement = document.createElement('div');
                cellElement.classList.add('cell');
                cellElement.dataset.row = i; // Store row index as data attribute
                cellElement.dataset.col = j; // Store column index as data attribute
                cellElement.setAttribute('contenteditable', 'true'); // Make cell editable
                cellElement.addEventListener('input', handleCellInput); // Add input event listener
                row.appendChild(cellElement);
            }
    
            gridContainer.appendChild(row);
        }
    }
    
    function endGame(){
        const div = document.getElementById('complete_page');


        div.innerHTML = '';

        document.getElementById('final_score').textContent='Performace Index is: '+get_performace_index(user_score,round_number);

        document.removeEventListener('keydown', handleKeyboardInput);



    }

    function get_performace_index(score, rounds) {
        // Check if number2 is not zero to avoid division by zero error
        if (rounds === 0) {
            return 0.00;
        }
    
        // Perform division and round the result to two decimal digits
        const result = (user_score / round_number).toFixed(2);
    
        return result;
    }

    //handles the edit during the setup stage
    function handleCellInput(event) {
        const row = event.target.dataset.row; // Get row index from data attribute
        const col = event.target.dataset.col; // Get column index from data attribute
        const value = event.target.innerText.toLowerCase(); // Get typed value
        
        const allowedCharacters = ['5', '6', '7', '8', 'o', 'h'];

        if(allowedCharacters.includes(value)==0){
            const errorMessage = 'Invalid input! Please enter a character from 5 to 8, o, or h.';
        
            // Display error message in the browser
            document.getElementById('error-message').textContent = errorMessage;

            event.target.innerText='';
        }else{
            const errorMessage = '';
            document.getElementById('error-message').textContent = errorMessage;
            grid[row][col]=value;//store the value in grid
        }

        console.log(`Typed "${value}" in cell (${row}, ${col})`);
        // You can perform further processing here based on the typed value
    }


    //checks the status and updates the 
    function checkValidGrid(){
        let cnt=0;
        cnt_5=0,cnt_6=0,cnt_7=0,cnt_8=0

        for(let i=0;i<10;i++){
            for(let j=0;j<10;j++){


                if(grid[i][j]=='h'){
                    hunter_x=i;
                    hunter_y=j;
                    cnt++;
                }

                if(grid[i][j]=='5'){
                    cnt_5++;
                }

                if(grid[i][j]=='6'){
                    cnt_6++;
                }

                if(grid[i][j]=='7'){
                    cnt_7++;
                }

                if(grid[i][j]=='8'){
                    cnt_8++;
                }
            }
        }

        console.log(cnt);

        return cnt==1;
    }



    //renders the grid at play stage
    function renderGridAfterMove(x,y){
        gridContainer.innerHTML = ''; // Clear previous grid

        for (let i = 0; i < 10; i++) {
            const row = document.createElement('div');
            row.classList.add('row'); // Adding a class for styling (optional)
            
            for (let j = 0; j < 10; j++) {
                const cellElement = document.createElement('div');
                cellElement.classList.add('cell');
                cellElement.dataset.row = i; // Store row index as data attribute
                cellElement.dataset.col = j; // Store column index as data attribute
                //cellElement.setAttribute('contenteditable', 'true'); // Make cell editable
                
                if(i==x && y==j){
                    cellElement.innerText='h';
                }


                row.appendChild(cellElement);
            }

            gridContainer.appendChild(row);
        }
    }
    
    


    initializeGrid();
    renderGrid();






    //document.getElementById('setup-btn').addEventListener('click', setupGame);
    document.getElementById('play-btn').addEventListener('click', playGame);
    document.getElementById('end-btn').addEventListener('click', endGame);

    //function to choose random free cell to place the obstacle
    function chooseRandom(){


        while(1){
            x=Math.floor(Math.random() * 9);
            y=Math.floor(Math.random() * 9);
            if(grid[x][y]==''){
                grid[x][y]='o';
                break;
            }
        }

    }
    

    //function to update score
    function UpdateScore(current){
        
        console.log(current);
        if(current=='5'){
            user_score+=5;
            cnt_5--;
        }

        if(current=='6'){
            user_score+=6;
            cnt_6--;
        }

        if(current=='7'){
            user_score+=7;
            cnt_7--;
        }

        if(current=='8'){
            user_score+=8;
            cnt_8--;
        }

        console.log(user_score);

    }


    //function to render the status of game after each round
    function updateStatus(){    




        document.getElementById('round_counter').textContent = 'Rounds completed: '+ round_number;
        document.getElementById('treasure_5_counter').textContent = 'Treasure of type 5 left: '+ cnt_5;
        document.getElementById('treasure_6_counter').textContent = 'Treasure of type 6 left: '+ cnt_6;
        document.getElementById('treasure_7_counter').textContent = 'Treasure of type 7 left: '+ cnt_7;
        document.getElementById('treasure_8_counter').textContent = 'Treasure of type 8 left: '+ cnt_8;
        document.getElementById('score_counter').textContent = 'Score: '+ user_score;
           
        
    }


    //check if any move is poosible from (x,y)
    function Movepossible(x,y){


        
        if(cnt_5==0 && cnt_6==0 && cnt_7==0 && cnt_8==0){
            return 0;
        }
        
        if(x+1<10 && grid[x][y]!='o'){
            return 1;
        }

        if(x-1>=0 && grid[x][y]!='o'){
            return 1;
        }

        if(y-1>=0 && grid[x][y]!='o'){
            return 1;
        }

        if(y+1<10 && grid[x][y]!='o'){
            return 1;
        }

        return 0;
    }


    function handleKeyboardInput(event){

        const keyPressed = event.key.toLowerCase();

        if(keyPressed!='a' && keyPressed!='d' && keyPressed!='w' && keyPressed!='s'){
            alert('Wrong key presses');
            return;
        }


        

        if(keyPressed=='a'){

            if(hunter_y==0 || grid[hunter_x][hunter_y-1]=='o'){
                alert('Invalid Move');
                return;
            }

            grid[hunter_x][hunter_y]='';
            hunter_y--;
                    
        }

        
        if(keyPressed=='d'){
            if(hunter_y==9 || grid[hunter_x][hunter_y+1]=='o'){
                alert('Invalid Move');
                return;
            }
            grid[hunter_x][hunter_y]='';
            hunter_y++;
        }

        if(keyPressed=='s'){
            if(hunter_x==9 || grid[hunter_x+1][hunter_y]=='o'){
                alert('Invalid Move');
                return;
            }
            
            grid[hunter_x][hunter_y]='';
            hunter_x++;
        }

        if(keyPressed=='w'){
            if(hunter_x==0 || grid[hunter_x-1][hunter_y]=='o'){
                alert('Invalid Move');
                return;
            }
            grid[hunter_x][hunter_y]='';
            hunter_x--;
        }

        round_number++;
        let current=grid[hunter_x][hunter_y];
        UpdateScore(current);
        updateStatus();
        chooseRandom();
        renderGridAfterMove(hunter_x,hunter_y);

        if(Movepossible(hunter_x,hunter_y)==0){
            endGame();
        }

        




    }


    function playGame() {
        // Check if the game is set up


        if (checkValidGrid()==0) {

            const errorMessage = 'Game not setup yet , Exactly 1 hunter should be there in grid';

        
            // Display error message in the browser
            document.getElementById('error-message').textContent = errorMessage;

    
            return;
        }
    
        //play logic goes here


        document.getElementById('title').textContent = 'Game is now playing.';
        gridContainer.innerHTML = ''; // Clear previous grid
        



        for (let i = 0; i < 10; i++) {
            const row = document.createElement('div');
            row.classList.add('row'); // Adding a class for styling (optional)
            
            for (let j = 0; j < 10; j++) {
                const cellElement = document.createElement('div');
                cellElement.classList.add('cell');
                cellElement.dataset.row = i; // Store row index as data attribute
                cellElement.dataset.col = j; // Store column index as data attribute
                //cellElement.setAttribute('contenteditable', 'true'); // Make cell editable
                cellElement.innerText=grid[i][j];
                row.appendChild(cellElement);
            }

            gridContainer.appendChild(row);
        }
        
        


        setTimeout(function() {
            // Execute Function 2 after a delay of 2000 milliseconds (2 seconds)
            renderGridAfterMove(hunter_x,hunter_y);

            updateStatus();

            if(Movepossible(hunter_x,hunter_y)==0){
                endGame();
            }
            document.addEventListener('keydown', handleKeyboardInput);
        }, 2000);




        

        




    }
});
