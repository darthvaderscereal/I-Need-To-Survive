// // Zombie1 texture 
    // sf::Texture zombieTexture;
    // if (!zombieTexture.loadFromFile("C:\\Users\\kgg61\\Documents\\sfml-project\\characters\\zombie_placeholder.png")) {
    //     std::cerr << "Zombie unable to load" << std::endl;
    //     exit(1); // Compiler is informed that the zombie could not load successfully
    // }

    // // Zombie1 creation
    // sf::Sprite zombieSprite;
    // zombieSprite.setTexture(zombieTexture);
    // float zombieXPosition = -25.f;
    // float zombieYPosition = 680.f;
    // zombieSprite.setPosition(100, 100);
    // zombieSprite.setScale(sf::Vector2f(0.3f, 0.3f));

    
    // // Blood texture loading
    // sf::Texture bloodTexture;
    // if (!bloodTexture.loadFromFile("C:\\Users\\kgg61\\Documents\\sfml-project\\characters\\blood_splatter.png")) {
    //     std::cerr << "Blood is not loading" << std::endl;
    //     exit(1); // Compiler is informed that the blood could not load successfully
    // }

    // // Blood creation
    // sf::Sprite bloodSprite;
    // bloodSprite.setTexture(bloodTexture);
    // bloodSprite.setScale(sf::Vector2f(0.1f, 0.1f));
    // bloodSprite.setPosition(-500, -500); // Hides initial blood from default position (0,0)
    // bool bloodVisible = false;

    // Boolean values
    // bool zombieMoving = true;
    // bool respawnOccurred = false;
    // bool collisionOccurred = false;

    // If true, zombie moves to the right relative to the window
        // if (zombieMoving) {
        //     zombiePosition.x += zombieSpeed * deltaTime;
        // }

        // Collision between bullet and zombie
        // if (bulletSprite.getGlobalBounds().intersects(zombieSprite.getGlobalBounds())) {
        //     bloodSprite.setPosition(zombieSprite.getPosition());
        //     bulletActive = false;
        //     zombieMoving = false;
        //     collisionOccurred = true;
        //     respawnOccurred = true;
        //     bloodVisible = true;
        //     bulletPosition.x = characterXPosition; // Spawns bullet at character's position
        //     std::cout << "collision" << std::endl;
        // }

        // If collision occurred and 3 seconds have passed, zombie "respawns" on the left side of window
        // if (collisionOccurred && collisionClock.getElapsedTime().asSeconds() >= 3) {
        //         zombiePosition.x = -190.f; // Zombie's respawn position 
        //         bloodVisible = false;
        //         // bloodSprite.setPosition(-500.f, -500.f); // Blood "disappears"
        //         collisionClock.restart(); // Activates the zombie to move forward
        // }

        // If 5 seconds have passed after zombie "respawns", zombie moves to the right once again
        // if (respawnOccurred && respawnClock.getElapsedTime().asSeconds() >= 5) {
        //     zombieMoving = true;
        //     std::cout << "Zombie is now moving after 5 seconds" << std::endl;
            
        // }