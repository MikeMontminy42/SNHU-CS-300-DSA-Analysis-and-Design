# SNHU-CS-300-DSA-Analysis-and-Design


# What was the problem you were solving in the projects for this course?
The main problem that needed to be solved was developing a simple command prompt application that allowed an advisor to organize and present course information at a moments notice. The program needed to be able to read a CSV file containing all course names, IDs, and prerequisites. The program also needed to be able to store the data easily and allow for user interactions with that data through a small menu.


# How did you approach the problem? Consider why data structures are important to understand.
My first idea was to determine which data structure would be the best to use out of a vector, linked list, hash table, and a binary search tree. In the end I ended up going with a vector for simplicity, flexibility, and easy to work with if the course count increases. Having a proper understanding of these data strucutres is crucial considering it helps to ensure a programs overall scalability and efficiency if many things have to change such as data amount or functionality changes. 


# How did you overcome any roadblocks you encountered while going through the activities or projects?
The biggest issue for the final project was parsing the CSV file manually without having a parser file from activites before. The way I solved the issue was by going character by character in each line and using logic to detect and make the commas be a string splitter. Some other issues were dealing with courses that ended up having no prerequisites and inputs not all uppercase. These two got fixed up by implementing sting validation and forcing the program to convert all inputs to full uppercase to be safe. 


# How has your work on this project expanded your approach to designing software and developing programs?
This project and the assignments within this course helped me to realize that I have little to no recursive thinking. The project specifically helped me to properly understand the benefits of breaking down problems into separate parts such as grabbing the name of the data file, parsing the data file, sorting the data within the file, storing the data within a structure, and general user interactability. It also helped me see how crucial having clean and simple code makes a massive difference when it comes to updating or changing items later down the road.

# How has your work on this project evloved the way you write programs that are maintainable, readable, and adaptable?

Through the project I've learned to adjust my overall naming conventions for variables so the code is a bit more readable. For the longest time I've had most of my variable names be vague, and originally most of the actual readability was done through the comments. I've also learned to add proper input validation for every possible case that could occur which helps out with random errors or infinite loops that could occur. Having all of these together has helped make the project and assignment from earlier in the course much easier to read and use. It also helps if I plan to reuse any code from these for personal projects later down the line.
