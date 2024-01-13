#include<EEPROM>
void writeIntIntoEEPROM(int address, int number){ 
  EEPROM.write(address, number >> 8);
  EEPROM.write(address + 1, number & 0xFF);
}
int readIntFromEEPROM(int address){
  byte byte1 = EEPROM.read(address);
  byte byte2 = EEPROM.read(address + 1);
  return (byte1 << 8) + byte2;
} 
void Snake::execute(){
  Block* tail = _blocks[0];
  //SWITCH CASE HAVE BUG!!!!
  if(_direction == UP)
  {
    moveUp(tail);
  }
  else if(_direction == DOWN)
  {
    moveDown(tail);
  }
  else if(_direction == RIGHT)
  {
    moveRight(tail);
  }
  else if(_direction == LEFT)
  {
    moveLeft(tail);
  }
  for(int j = 0;j<_size;j++)
  {
    _blocks[j]=_blocks[j+1];
  }  
  _blocks[_size-1] = tail;
  _headX = tail->_x;
  _headY = tail->_y;
  for(int j = 0;j<_size-1;j++)
  {
    if(_blocks[j]->_x == _headX &&
        _blocks[j]->_y == _headY)
    {
      _selfTouch=true;
    }
  }  
  draw();
}
void Snake::moveRight(Block* tail){
  if(_blocks[_size-1]->_x + WEIGHT != WIDTH)
  {
    tail->_x=_blocks[_size-1]->_x + WEIGHT;
    tail->_y=_blocks[_size-1]->_y;
  }
  else
  {
    tail->_x=0;
    tail->_y=_blocks[_size-1]->_y;
  }
}
void Snake::moveUp(Block* tail){
  if(_blocks[_size-1]->_y != 0)
  {
    tail->_y=_blocks[_size-1]->_y - WEIGHT;
    tail->_x = _blocks[_size-1]->_x;
  }
  else
  {
    tail->_y = HEIGHT - WEIGHT;
    tail->_x = _blocks[_size-1]->_x;
  }
}
void Snake::moveDown(Block* tail){
  if(_blocks[_size-1]->_y + WEIGHT != HEIGHT)
  {
    tail->_y = _blocks[_size-1]->_y + WEIGHT;
    tail->_x = _blocks[_size-1]->_x;
  }
  else
  {
    tail->_y = 0;
    tail->_x = _blocks[_size-1]->_x;
  }
}
void Snake::moveLeft(Block* tail){
  if(_blocks[_size-1]->_x != 0)
  {
    tail->_x=_blocks[_size-1]->_x - WEIGHT;
    tail->_y=_blocks[_size-1]->_y;
  }
  else
  {
    tail->_x = WIDTH - WEIGHT;
    tail->_y = _blocks[_size-1]->_y;
  }  
}
void Snake::draw(){
  for (byte i = 0; i < _size; i ++) {
    _display->fillRect(_blocks[i]->_x, _blocks[i]->_y, _weight, _weight, BLACK);
  }
}
void GameManager::checkForCollision()
{
  //check collision with food
  if(_food->_x == _snake->_headX &&
  _food->_y == _snake->_headY)
  {
            if(_sound)
            {
                tone(SPEAKER, NOTE_A7, TONE_FOOD_DURATION);
            }
      score+=_food->points;
      _snake->addBlock(_food->_x, _food->_y);
      _food->randomize(WIDTH - WEIGHT, HEIGHT - WEIGHT, WEIGHT);
  }
}
void Food::randomize(byte width, byte height, byte weight){
  _x = random(weight,width - weight);
  if(_x % weight != 0)
      _x+=1;
  _y = random(2,height -weight);
  if(_y % weight != 0)
      _y+=1;
}
