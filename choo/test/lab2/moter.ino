void MoterNO(){
  mcp.digitalWrite(MCP_LEDTOG2, 0);
  mcp.digitalWrite(MCP_LEDTOG1, 1023);
}
void MoterOFF(){
  mcp.digitalWrite(MCP_LEDTOG2, 0);
  mcp.digitalWrite(MCP_LEDTOG1, 0);
}

void MoterRE(){
  mcp.digitalWrite(MCP_LEDTOG2, 500);
  mcp.digitalWrite(MCP_LEDTOG1, 0);
}

