#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

int main() {
    sf::RenderWindow window(sf::VideoMode(1800, 950), "I Need To Survive", sf::Style::Default);
    window.setFramerateLimit(60); // Frame rate at 60 fps
    
    // Background texture
    sf::Texture backgroundTexture;
    if (!backgroundTexture.loadFromFile("C:\\Users\\kgg61\\Documents\\sfml-project\\background_images\\forest_background.jpg")) {
        std::cerr << "Background unable to load" << std::endl;
        exit(1); // Compiler is informed that the background could not load successfully
    }
    
    // Background creation
    sf::Sprite backgroundSprite;
    backgroundSprite.setTexture(backgroundTexture);
    backgroundSprite.setScale(sf::Vector2f(4.f, 4.5f));

    // Character texture 
    sf::Texture characterTexture;
    if (!characterTexture.loadFromFile("C:\\Users\\kgg61\\Documents\\sfml-project\\characters\\spritesheet.png")) { // If image doesn't load
        std::cerr << "Character unable to load" << std::endl;
        exit(1); // Compiler is informed that the character could not load successfully
    }

    // Character creation
    sf::Sprite characterSprite;
    characterSprite.setTexture(characterTexture);
    float characterXPosition = 1400.f;
    float characterYPosition = 400.f;
    characterSprite.setScale(sf::Vector2f(0.2f, 0.2f)); // Absolute scale factor
    float characterSpeed = 300.f; // Speed movement of the character

    // Sprite sheet has 6 frames
    const int frameCount = 6; 
    int frameWidth = characterTexture.getSize().x / frameCount;  // X axis = width of each frame within sprite sheet
    int frameHeight = characterTexture.getSize().y; // Y axis = height of each frame within sprite sheet
    sf::IntRect frameRect(0, 0, frameWidth, frameHeight); // x-coordinate of top-left corner, y-coordinate of top-left corner, width, height
    characterSprite.setTextureRect(frameRect);
    characterSprite.setPosition(characterXPosition, characterYPosition); // Sets initial position of character
    int currentFrame = 0; // First frame of spritesheet

    // M1911 texture
    sf::Texture M1911Texture;
    if (!M1911Texture.loadFromFile("C:\\Users\\kgg61\\Documents\\sfml-project\\characters\\M1911.png")) {
        std::cerr << "M1911 unable to load" << std::endl;
        exit(1); // Compiler is informed that the M1911 could not load successfully
    }

    // M1911 creation
    sf::Sprite M1911Sprite;
    M1911Sprite.setTexture(M1911Texture);
    M1911Sprite.setScale(sf::Vector2f(0.2f, 0.2f));
    sf::Vector2f M1911Offset(25.f, 160.f); // Defines a constant offset for the pistol relative to the character (25 pixels to the right, 160 pixels lower)

    // Bullet texture loading
    sf::Texture bulletTexture;
    if (!bulletTexture.loadFromFile("C:\\Users\\kgg61\\Documents\\sfml-project\\characters\\bullet.png")) {
        std::cerr << "Bullet unable to load" << std::endl;
        exit(1); // Compiler is informed that the bullet could not load successfully
    }

    // Bullet creation
    sf::Sprite bulletSprite;
    bulletSprite.setTexture(bulletTexture);
    bulletSprite.setScale(sf::Vector2f(0.2f, 0.2f)); // Absolute scale factor
    bool bulletActive = false; 
    float bulletSpeed = 1500.f; // Speed of the bullet

    // Time measurement
    sf::Clock gameClock; // Measures time that has elapsed between frames (delta time)
    sf::Clock collisionClock; // Measures time since collision
    sf::Clock frameClock; // Measures frame updates
    sf::Clock respawnClock; // Measures zombie respawn (*will implement later*)
    
    // float zombieSpeed = 200.f; // Speed movement of the zombie1; *Will implement later*

    // Game loop
    while (window.isOpen()) {
        // Updates sprite positions
        sf::Vector2f characterPosition = characterSprite.getPosition();
        // sf::Vector2f zombiePosition = zombieSprite.getPosition(); // *Will implement later*
        sf::Vector2f bulletPosition = bulletSprite.getPosition();
        sf::Vector2f M1911Position = M1911Sprite.getPosition();

        sf::Time elapsed = frameClock.getElapsedTime();
        float deltaTime = gameClock.restart().asSeconds();

        // When "A" button is pressed, character moves left
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) { 
            characterPosition.x -= characterSpeed * deltaTime; // Character moves left relative to screen
            // M1911XPosition -= characterSpeed * deltaTime;
            // M1911Position.x -= M1911Speed * deltaTime; // M1911 moves left
            // M1911XPosition = characterPosition.x; // Forbids the M1911 to shift away; "glues" it to the character

            if (frameClock.getElapsedTime().asSeconds() >= 0.1f) { // Each frame of the spritesheet gets displayed per 0.1 second (forward)
                currentFrame = (currentFrame +  1) % frameCount;
                frameRect.left = currentFrame * frameWidth;
                characterSprite.setTextureRect(frameRect);
                frameClock.restart();
            }
        }

        // When "D" button is pressed, character moves right
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
            characterPosition.x += characterSpeed * deltaTime; // Character moves right relative to screen
            // M1911XPosition += characterSpeed * deltaTime;
            // M1911Position.x += M1911Speed * deltaTime; // M1911 moves right
            // M1911XPosition = characterPosition.x; // Forbids the M1911 to shift away; "glues" it to the character

            if (frameClock.getElapsedTime().asSeconds() >= 0.1f) { // Each frame of the spritesheet gets displayed per 0.1 second ("backwards")
                currentFrame = (currentFrame +  1) % frameCount;
                frameRect.left = currentFrame * frameWidth;
                characterSprite.setTextureRect(frameRect);
                frameClock.restart();
            }
        }

        std::cout << "gun's x position: " << M1911Position.x << std::endl;

        // Invisible "walls" to ensure character stays within bounds
        if (characterPosition.x >= 1480.f) { // Invisible "wall" at x position of 1480
            characterPosition.x = 1480.f;
            // M1911XPosition = characterXPosition;
        }

        if (characterPosition.x <= 1200.f) { // Invisible "wall" at x position of 1200
            characterPosition.x = 1200.f;
            // M1911Position.x = 1300.f;
        }  

        // Handling events
        sf::Event event;
        while (window.pollEvent(event)) { // While there are pending events...
            if (event.type == sf::Event::Closed) { // If the type of event is "Closed", window will close
                window.close();
            }

            // If "A" button is released, character's frame defaults back to the first frame (0)
            if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::A) {
                std::cout << "A button is released \n";
                currentFrame = 0;
                frameClock.restart();
            }

            // If "D" button is released, character's frame defaults back to the first frame (0)
            if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::D) {
                std::cout << "D button is released \n";
                currentFrame = 0;
                frameClock.restart();
            }
        }
        
        // SFML "cutting out" the respective rectangle(s) from sprite sheet and displaying the frames desired
        characterSprite.setTextureRect(sf::IntRect(currentFrame * frameWidth, 0, frameWidth, frameHeight)); // Updates the sprite's texture rectangle to display correct frame

        // std::cout << "character's x position: " << characterPosition.x << std::endl;
        // std::cout << "character's y position: " << characterPosition.y << std::endl;

        // Left mouse click = gun shoots
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
            std::cout << "Left mouse button clicked" << std::endl;
            bulletActive = true;
        }

        // Once gun gets shot, bullet travels left relative to the game window
        if (bulletActive) {
                bulletPosition.x -= bulletSpeed * deltaTime;
        }

        characterSprite.setPosition(characterPosition);
        // zombieSprite.setPosition(zombiePosition);
        bulletSprite.setPosition(bulletPosition);
        M1911Sprite.setPosition(characterPosition + M1911Offset);

        // Rendering
        window.clear();
        window.draw(backgroundSprite);
        window.draw(characterSprite);
        window.draw(M1911Sprite);
        // window.draw(zombieSprite);
        if (bulletActive) { 
            window.draw(bulletSprite);
        }
        // if (bloodVisible) {
        //     window.draw(bloodSprite);
        // } 
        window.display();
    }
}